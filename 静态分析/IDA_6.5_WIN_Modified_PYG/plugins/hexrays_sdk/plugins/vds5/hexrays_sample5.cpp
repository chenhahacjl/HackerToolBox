/*
 *      Hex-Rays Decompiler project
 *      Copyright (c) 2007-2008 by Hex-Rays, support@hex-rays.com
 *      ALL RIGHTS RESERVED.
 *
 *      Sample plugin for the Hex-Rays Decompiler.
 *      It adds a new command to show graph of the ctree.
 *      The current item will be highlighted in the graph.
 *
 *      The command hotkey is G. It is also added into the right-click menu.
 *
 *      To display the graph, we traverse the ctree and build
 *      a gdl_graph_t object. Then we use gen_gdl() function from IDA
 *      to create a GDL file from this object. Finally, we call
 *      wingraph32 to display the graph on the screen.
 *
 */

#include <hexrays.hpp>
#include <gdl.hpp>

// Hex-Rays API pointer
hexdsp_t *hexdsp = NULL;

static bool inited = false;

// Hotkey for the new command
static const char hotkey[] = "G";
static ushort hotcode;

//-------------------------------------------------------------------------
//                        red      green       blue
#define CL_WHITE         ((255)+  (255<<8)+  (255<<16)) //   0
#define CL_BLUE          ((0  )+  (0  <<8)+  (255<<16)) //   1
#define CL_RED           ((255)+  (0  <<8)+  (0  <<16)) //   2
#define CL_GREEN         ((0  )+  (255<<8)+  (0  <<16)) //   3
#define CL_YELLOW        ((255)+  (255<<8)+  (0  <<16)) //   4
#define CL_MAGENTA       ((255)+  (0  <<8)+  (255<<16)) //   5
#define CL_CYAN          ((0  )+  (255<<8)+  (255<<16)) //   6
#define CL_DARKGREY      ((85 )+  (85 <<8)+  (85 <<16)) //   7
#define CL_DARKBLUE      ((0  )+  (0  <<8)+  (128<<16)) //   8
#define CL_DARKRED       ((128)+  (0  <<8)+  (0  <<16)) //   9
#define CL_DARKGREEN     ((0  )+  (128<<8)+  (0  <<16)) //  10
#define CL_DARKYELLOW    ((128)+  (128<<8)+  (0  <<16)) //  11
#define CL_DARKMAGENTA   ((128)+  (0  <<8)+  (128<<16)) //  12
#define CL_DARKCYAN      ((0  )+  (128<<8)+  (128<<16)) //  13
#define CL_GOLD          ((255)+  (215<<8)+  (0  <<16)) //  14
#define CL_LIGHTGREY     ((170)+  (170<<8)+  (170<<16)) //  15
#define CL_LIGHTBLUE     ((128)+  (128<<8)+  (255<<16)) //  16
#define CL_LIGHTRED      ((255)+  (128<<8)+  (128<<16)) //  17
#define CL_LIGHTGREEN    ((128)+  (255<<8)+  (128<<16)) //  18
#define CL_LIGHTYELLOW   ((255)+  (255<<8)+  (128<<16)) //  19
#define CL_LIGHTMAGENTA  ((255)+  (128<<8)+  (255<<16)) //  20
#define CL_LIGHTCYAN     ((128)+  (255<<8)+  (255<<16)) //  21
#define CL_LILAC         ((238)+  (130<<8)+  (238<<16)) //  22
#define CL_TURQUOISE     ((64 )+  (224<<8)+  (208<<16)) //  23
#define CL_AQUAMARINE    ((127)+  (255<<8)+  (212<<16)) //  24
#define CL_KHAKI         ((240)+  (230<<8)+  (140<<16)) //  25
#define CL_PURPLE        ((160)+  (32 <<8)+  (240<<16)) //  26
#define CL_YELLOWGREEN   ((154)+  (205<<8)+  (50 <<16)) //  27
#define CL_PINK          ((255)+  (192<<8)+  (203<<16)) //  28
#define CL_ORANGE        ((255)+  (165<<8)+  (0  <<16)) //  29
#define CL_ORCHID        ((218)+  (112<<8)+  (214<<16)) //  30
#define CL_BLACK         ((0  )+  (0  <<8)+  (0  <<16)) //  31

//-------------------------------------------------------------------------
// Convert internal background color code into textual form for GDL
static const char *get_color_name(bgcolor_t c)
{
  switch ( c )
  {
    case CL_WHITE       : return "white";
    case CL_BLUE        : return "blue";
    case CL_RED         : return "red";
    case CL_GREEN       : return "green";
    case CL_YELLOW      : return "yellow";
    case CL_MAGENTA     : return "magenta";
    case CL_CYAN        : return "cyan";
    case CL_DARKGREY    : return "darkgrey";
    case CL_DARKBLUE    : return "darkblue";
    case CL_DARKRED     : return "darkred";
    case CL_DARKGREEN   : return "darkgreen";
    case CL_DARKYELLOW  : return "darkyellow";
    case CL_DARKMAGENTA : return "darkmagenta";
    case CL_DARKCYAN    : return "darkcyan";
    case CL_GOLD        : return "gold";
    case CL_LIGHTGREY   : return "lightgrey";
    case CL_LIGHTBLUE   : return "lightblue";
    case CL_LIGHTRED    : return "lightred";
    case CL_LIGHTGREEN  : return "lightgreen";
    case CL_LIGHTYELLOW : return "lightyellow";
    case CL_LIGHTMAGENTA: return "lightmagenta";
    case CL_LIGHTCYAN   : return "lightcyan";
    case CL_LILAC       : return "lilac";
    case CL_TURQUOISE   : return "turquoise";
    case CL_AQUAMARINE  : return "aquamarine";
    case CL_KHAKI       : return "khaki";
    case CL_PURPLE      : return "purple";
    case CL_YELLOWGREEN : return "yellowgreen";
    case CL_PINK        : return "pink";
    case CL_ORANGE      : return "orange";
    case CL_ORCHID      : return "orchid";
    case CL_BLACK       : return "black";
  }
  return "?";
}

//--------------------------------------------------------------------------
// Since we can not directly display cfunc_t as a graph, we build a graph
// object which will be saved as a GDL file and displayed with wingraph32.
class cfunc_graph_t : public gdl_graph_t
{
  typedef qvector<const citem_t *> itemrefs_t;
  itemrefs_t items;
  const citem_t *highlight;     // item to highlight
  friend struct graph_builder_t;
  array_of_intseq_t succs;
  array_of_intseq_t preds;
  int  idaapi nsucc(int b) const  { return size() ? succs[b].size() : 0; }
  int  idaapi npred(int b) const  { return size() ? preds[b].size() : 0; }
  int  idaapi succ(int b, int i) const { return succs[b][i]; }
  int  idaapi pred(int b, int i) const { return preds[b][i]; }
public:
  cfunc_graph_t(const citem_t *_highlight) : highlight(_highlight) {}
  int idaapi size(void) const { return preds.size(); }
  int add_node(void)
  {
    int n = size();
    preds.resize(n+1);
    succs.resize(n+1);
    return n;
  }
  void add_edge(int x, int y)
  {
    preds[y].push_back(x);
    succs[x].push_back(y);
  }
  // Display a graph node. Feel free to modify this function to fine tune the node display.
  char *idaapi get_node_label(int n, char *buf, int bufsize) const
  {
    char *ptr = buf;
    char *end = buf + bufsize;
    // Get the corresponding ctree item
    const citem_t *item = items[n];
    // Each node will have the element type at the first line
    APPEND(ptr, end, get_ctype_name(item->op));
    const cexpr_t *e = (const cexpr_t *)item;
    const cinsn_t *i = (const cinsn_t *)item;
    // For some item types, display additional information
    switch ( item->op )
    {
      case cot_ptr     : // *x
      case cot_memptr  : // x->m
        // Display access size for pointers
        ptr += qsnprintf(ptr, end-ptr, ".%d", e->ptrsize);
        if ( item->op == cot_ptr )
          break;
      case cot_memref  : // x.m
        // Display member offset for structure fields
        ptr += qsnprintf(ptr, end-ptr, " (m=%d)", e->m);
        break;
      case cot_obj     : // v
      case cot_var     : // l
        // Display object size for local variables and global data
        ptr += qsnprintf(ptr, end-ptr, ".%d", e->refwidth);
      case cot_num     : // n
      case cot_helper  : // arbitrary name
      case cot_str     : // string constant
        // Display helper names and number values
        APPCHAR(ptr, end, ' ');
        e->print1(ptr, end-ptr, NULL);
        tag_remove(ptr, ptr, 0);
        ptr = tail(ptr);
        break;
     case cit_goto:
        // Display target label number for gotos
        ptr += qsnprintf(ptr, end-ptr, " LABEL_%d", i->cgoto->label_num);
        break;
     case cit_asm:
        // Display instruction block address and size for asm-statements
        ptr += qsnprintf(ptr, end-ptr, " %a.%d", *i->casm->begin(), i->casm->size());
        break;
    }
    // The second line of the node contains the item address
    ptr += qsnprintf(ptr, end-ptr, "\nea: %a", item->ea);
    if ( item->is_expr() && !e->type.empty() )
    {
      // For typed expressions, the third line will have
      // the expression type in human readable form
      APPCHAR(ptr, end, '\n');
      if ( print_type_to_one_line(ptr, end-ptr, idati, e->type.u_str()) != T_NORMAL )
      { // could not print the type?
        APPCHAR(ptr, end, '?');
        APPZERO(ptr, end);
      }
    }
    return buf;
  }
  // Display a graph edge.
  bool idaapi print_edge(FILE *fp, int i, int j) const
  {
    qfprintf(fp, "edge: { sourcename: \"%d\" targetname: \"%d\" ", i, j);
    char *label = NULL;
    const citem_t *a = items[i];
    const citem_t *b = items[j];
    if ( a->is_expr() ) // For expressions, add labels to the edges
    {
      cexpr_t *e = (cexpr_t *)a;
      if ( e->x == b ) label = "x";
      if ( e->y == b ) label = "y";
      if ( e->z == b ) label = "z";
    }
    if ( label != NULL )
      qfprintf(fp, "label: \"%s\" ", label);
    qfprintf(fp, "}\n");
    return true;
  }
  // Determine the node color. Feel free to change it.
  bgcolor_t idaapi get_node_color(int n) const
  {
    const citem_t *item = items[n];
    if ( item == highlight )
      return CL_GREEN;          // Highlighted item
    if ( item->is_expr() )
    {
      char buf[MAXSTR];
      const cexpr_t *e = (const cexpr_t *)item;
      if ( print_type_to_one_line(buf, sizeof(buf), idati, e->type.u_str()) != T_NORMAL )
        return CL_YELLOWGREEN; // Problematic type
    }
    return DEFCOLOR;
  }
  // Print the node color.
  void idaapi print_node_attributes(FILE *fp, int n) const
  {
    bgcolor_t c = get_node_color(n);
    if ( c != DEFCOLOR )
      qfprintf(fp, " color: %s", get_color_name(c));
  }
};

//--------------------------------------------------------------------------
// Helper class to build graph from ctree.
struct graph_builder_t : public ctree_parentee_t
{
  cfunc_graph_t &cg;                 // Resulting graph
  std::map<citem_t *, int> reverse;  // Reverse mapping for tests and adding edges

  graph_builder_t(cfunc_graph_t &_cg) : cg(_cg) {}
  int add_node(citem_t *i);
  int process(citem_t *i);
  // We treat expressions and statements the same way: add them to the graph
  int idaapi visit_insn(cinsn_t *i) { return process(i); }
  int idaapi visit_expr(cexpr_t *e) { return process(e); }
};

// Add a new node to the graph
int graph_builder_t::add_node(citem_t *i)
{
  // Check if the item has already been encountered during the traversal
  if ( reverse.find(i) != reverse.end() )
  {
    warning("bad ctree - duplicate nodes!");
    return -1;
  }
  // Add a node to the graph
  int n = cg.add_node();
  // Remember the pointer to the item, we will need it to generate GDL
  // (in print_node_label)
  if ( n <= cg.items.size() )
    cg.items.push_back(i);
  cg.items[n] = i;
  // Also remember the reverse mapping (citem_t* -> n)
  reverse[i] = n;
  return n;
}

// Process a ctree item
int graph_builder_t::process(citem_t *item)
{
  // Add a node for citem
  int n = add_node(item);
  if ( n == -1 )
    return -1; // error

  if ( parents.size() > 1 )             // The current item has a parent?
  {
    int p = reverse[parents.back()];    // Parent node number
    cg.add_edge(p, n);                  // Add edge from the parent to the current item
  }
  return 0;
}

//--------------------------------------------------------------------------
// Build and display graph for the ctree
static bool idaapi display_graph(void *ud)
{
  vdui_t &vu = *(vdui_t *)ud;
  // Determine the ctree item to highlight
  vu.get_current_item(USE_KEYBOARD);
  citem_t *highlight = vu.item.is_citem() ? vu.item.e : NULL;

  cfunc_graph_t cg(highlight);  // Graph to display
  graph_builder_t gb(cg);       // Graph builder helper class
  // Build the graph by traversing the ctree
  gb.apply_to(&vu.cfunc->body, NULL);

  // Our graph object 'cg' is ready. Now display it by converting it to GDL
  // and calling wingraph32
  char fname[QMAXPATH];
  qtmpnam(fname, sizeof(fname));        // Generate temporary file name
  gen_gdl(&cg, fname);                  // Generate GDL file from 'cg' graph
  display_gdl(fname);                   // Display the GDL file
  return true;                          // Success!
}

//--------------------------------------------------------------------------
// This callback handles various hexrays events.
static int idaapi callback(void *, hexrays_event_t event, va_list va)
{
  switch ( event )
  {
    case hxe_right_click:
      {
        vdui_t &vu = *va_arg(va, vdui_t *);
        // add new command to the popup menu
        add_custom_viewer_popup_item(vu.ct, "Display graph", hotkey, display_graph, &vu);
      }
      break;

    case hxe_keyboard:
      {
        vdui_t &vu = *va_arg(va, vdui_t *);
        int keycode = va_arg(va, int);
        int shift = va_arg(va, int);
        // check for the hotkey
        if ( lookup_key_code(keycode, shift, true) == hotcode && shift == 0 )
          return display_graph(&vu);
      }
      break;
  }
  return 0;
}

//--------------------------------------------------------------------------
// Initialize the plugin.
int idaapi init(void)
{
  if ( !init_hexrays_plugin() )
    return PLUGIN_SKIP; // no decompiler
  install_hexrays_callback(callback, NULL);
  const char *hxver = get_hexrays_version();
  msg("Hex-rays version %s has been detected, %s ready to use\n", hxver, PLUGIN.wanted_name);
  inited = true;
  hotcode = get_key_code(hotkey); // convert the hotkey to binary form
  return PLUGIN_KEEP;
}

//--------------------------------------------------------------------------
void idaapi term(void)
{
  if ( inited )
  {
    remove_hexrays_callback(callback, NULL);
    term_hexrays_plugin();
  }
}

//--------------------------------------------------------------------------
void idaapi run(int)
{
  // This function won't be called because our plugin is invisible (no menu
  // item in the Edit, Plugins menu) because of PLUGIN_HIDE
}

//--------------------------------------------------------------------------
static char comment[] = "Sample plugin5 for Hex-Rays decompiler";

//--------------------------------------------------------------------------
//
//      PLUGIN DESCRIPTION BLOCK
//
//--------------------------------------------------------------------------
plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  PLUGIN_HIDE,          // plugin flags
  init,                 // initialize
  term,                 // terminate. this pointer may be NULL.
  run,                  // invoke plugin
  comment,              // long comment about the plugin
                        // it could appear in the status line or as a hint
  "",                   // multiline help about the plugin
  "Hex-Rays show C graph", // the preferred short name of the plugin
  ""                    // the preferred hotkey to run the plugin
};
