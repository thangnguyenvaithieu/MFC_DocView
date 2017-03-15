
// HaiND_613958_TH5.h : main header file for the HaiND_613958_TH5 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CHaiND_613958_TH5App:
// See HaiND_613958_TH5.cpp for the implementation of this class
//

class CHaiND_613958_TH5App : public CWinApp
{
public:
	CHaiND_613958_TH5App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHaiND_613958_TH5App theApp;
