
// FigureTest.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFigureTestApp:
// See FigureTest.cpp for the implementation of this class
//

class CFigureTestApp : public CWinApp
{
public:
	CFigureTestApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFigureTestApp theApp;
