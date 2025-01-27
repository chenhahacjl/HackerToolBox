// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include <windows.h>

#include "../../../EnigmaSDK/VC/enigma_ide.h"
#pragma comment (lib,"../../../EnigmaSDK/VC/enigma_ide.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDEXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

DWORD dwCounter = 0;

VOID CALLBACK TimerProcess( HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	CString Str;
	SYSTEMTIME lpSystemTime;
	DWORD dwTotalMinutes;
	DWORD dwLeftMunites;

	GetSystemTime(&lpSystemTime);

	// Set the global time	
	Str.Format("%.2d:%.2d:%.2d", lpSystemTime.wHour, lpSystemTime.wMinute, lpSystemTime.wSecond);
	SetDlgItemText(hwnd, IDC_EDIT_GLOBALTIME, (LPCTSTR)Str);

	// Set execution time
	Str.Format("%.2d:%.2d:%.2d", dwCounter / (60*60*1000) % 24, dwCounter / (60*1000) % 60, dwCounter / 1000 % 60);
	SetDlgItemText(hwnd, IDC_EDIT_EXECUTIONTIME, (LPCTSTR)Str);
	dwCounter += 500;

	// Set trial minutes
	if (EP_TrialExecutionTime(&dwTotalMinutes, &dwLeftMunites))
	{
		SetDlgItemText(hwnd, IDC_EDIT_STATUS, "OK");
		// Set parameters to edit fields
		Str.Format("%d", dwTotalMinutes); 
		SetDlgItemText(hwnd, IDC_EDIT_TOTAL, (LPCTSTR)Str);
		Str.Format("%d", dwLeftMunites); 
		SetDlgItemText(hwnd, IDC_EDIT_LEFT, (LPCTSTR)Str);
	} else
	{
		SetDlgItemText(hwnd, IDC_EDIT_STATUS, "UNUSED");				
	}    
}

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();	

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetTimer(0, 500, TimerProcess); 
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	ExitProcess(0);
	
}
