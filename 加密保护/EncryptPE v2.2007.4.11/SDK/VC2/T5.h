// T5.h : main header file for the T5 application
//

#if !defined(AFX_T5_H__1394AF10_B72A_4274_8BC1_AF97391764E4__INCLUDED_)
#define AFX_T5_H__1394AF10_B72A_4274_8BC1_AF97391764E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CT5App:
// See T5.cpp for the implementation of this class
//

class CT5App : public CWinApp
{
public:
	CT5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CT5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CT5App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_T5_H__1394AF10_B72A_4274_8BC1_AF97391764E4__INCLUDED_)
