
// FigureTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FigureTest.h"
#include "FigureTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFigureTestDlg dialog



CFigureTestDlg::CFigureTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_FIGURETEST_DIALOG, pParent),
	_angleFigure(0),
	_radiusFigure(100),
	_centralPointFigure(500, 300),
	_figure1(_centralPointFigure.x, _centralPointFigure.y, _radiusFigure, _angleFigure)
	, _expandKoef(0)
	, _rotateAngle(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	_timerVal = 0;
}

void CFigureTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TXT_EXPAND, _expandKoef);
	DDX_Text(pDX, IDC_TXT_ROTATE, _rotateAngle);
}

BEGIN_MESSAGE_MAP(CFigureTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ROTATE, &CFigureTestDlg::OnBnClickedBtnRotate)
	ON_BN_CLICKED(IDC_BTN_EXPAND, &CFigureTestDlg::OnBnClickedBtnExpand)
	ON_BN_CLICKED(IDC_BTN_START, &CFigureTestDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CFigureTestDlg::OnBnClickedBtnStop)
	ON_WM_TIMER()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BTN_RESET, &CFigureTestDlg::OnBnClickedBtnReset)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFigureTestDlg message handlers

BOOL CFigureTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	_backgroundBrush.CreateSolidBrush(RGB(255, 255, 255));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFigureTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFigureTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

		CPaintDC dc(this);
		_figure1.Show(&dc);
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFigureTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFigureTestDlg::OnBnClickedBtnRotate()
{
	UpdateData(TRUE);
	_figure1.Rotate(_rotateAngle);
	Invalidate();
}


void CFigureTestDlg::OnBnClickedBtnExpand()
{
	UpdateData(TRUE);
	if (_expandKoef <= 0) return;
	_figure1.Expand(_expandKoef);
	Invalidate();
	
}

void CFigureTestDlg::OnTimer(UINT_PTR uTimer)
{
	if (uTimer == 1)
	{
		_figure1.Rotate(0.05);
		InvalidateRect(_figure1.GetRectangle());
	}
}
void CFigureTestDlg::OnBnClickedBtnStart()
{
	_timerVal =  SetTimer(1, 20, NULL);
}


void CFigureTestDlg::OnBnClickedBtnStop()
{
	KillTimer(_timerVal);
}


void CFigureTestDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	_figure1.SetCentre(point);
	Invalidate();
	CDialog::OnLButtonUp(nFlags, point);
}


void CFigureTestDlg::OnBnClickedBtnReset()
{
	_figure1.SetCentre(_centralPointFigure);
	_figure1.SetRadius(_radiusFigure);
	_figure1.SetAngle(_angleFigure);

	Invalidate();
}


HBRUSH CFigureTestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	HBRUSH hbr = _backgroundBrush;

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
