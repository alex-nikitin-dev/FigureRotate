
// FigureTestDlg.h : header file
//

#pragma once
#include "Figure.h"

// CFigureTestDlg dialog
class CFigureTestDlg : public CDialog
{
private:
	CPoint const _centralPointFigure;
	double const _radiusFigure;
	double const _angleFigure;
	CBrush _backgroundBrush;
	Figure _figure1;
// Construction
public:
	CFigureTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIGURETEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	
	UINT _timerVal;
	

public:
	afx_msg void OnBnClickedBtnRotate();
	afx_msg void OnBnClickedBtnExpand();
	double _expandKoef;
	double _rotateAngle;
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnTimer(UINT_PTR);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnReset();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
