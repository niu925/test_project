// MyHelloView.h : interface of the CMyHelloView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYHELLOVIEW_H__4E5815CD_1EDC_45A3_A1C5_7A1CCB228342__INCLUDED_)
#define AFX_MYHELLOVIEW_H__4E5815CD_1EDC_45A3_A1C5_7A1CCB228342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
const WM_USEMSG=WM_USER+100;

class CMyHelloView : public CView
{
protected: // create from serialization only
	CMyHelloView();
	DECLARE_DYNCREATE(CMyHelloView)
	int m_nLine;              //存储回车次数
	CString m_strDisplay;        //存储当前行输入的字符

// Attributes
public:
	CMyHelloDoc* GetDocument();
    void onMyFunction();
// Operations
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyHelloView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyHelloView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CString m_MousePoint;
	//{{AFX_MSG(CMyHelloView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyHelloView.cpp
inline CMyHelloDoc* CMyHelloView::GetDocument()
   { return (CMyHelloDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYHELLOVIEW_H__4E5815CD_1EDC_45A3_A1C5_7A1CCB228342__INCLUDED_)
