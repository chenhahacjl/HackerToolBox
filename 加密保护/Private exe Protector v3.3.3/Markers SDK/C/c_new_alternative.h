#define begin_hide 
{ 
  __asm  {  DB 0xEB, 0x03, 0x99, 0x11, 0x99  }
}; 


#define end_hide 
{ 
  __asm  {  DB 0xEB, 0x03, 0x98, 0x11, 0x98  }
};


#define begin_key 
{ 
  __asm  {  DB 0xEB, 0x03, 0x99, 0x10, 0x99  }
}; 


#define end_key 
{ 
  __asm  {  DB 0xEB, 0x03, 0x98, 0x10, 0x98  }
};


#define begin_vm 
{ 
  __asm  {  DB 0xEB, 0x03, 0x99, 0x09, 0x99, 0x90 }
}; 


#define end_vm 
{ 
  __asm  {  DB 0xEB, 0x03, 0x98, 0x09, 0x98, 0x90 }
};

#define begin_morph 
{ 
  __asm  {  DB 0xEB, 0x03, 0x99, 0x08, 0x99, 0x90 }
}; 


#define end_morph 
{ 
  __asm  {  DB 0xEB, 0x03, 0x98, 0x08, 0x98, 0x90 }
};

