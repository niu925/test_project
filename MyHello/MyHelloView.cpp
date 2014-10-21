// MyHelloView.cpp : implementation of the CMyHelloView class
//

#include "stdafx.h"
#include "MyHello.h"

#include "MyHelloDoc.h"
#include "MyHelloView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyHelloView

IMPLEMENT_DYNCREATE(CMyHelloView, CView)

BEGIN_MESSAGE_MAP(CMyHelloView, CView)
	//{{AFX_MSG_MAP(CMyHelloView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(WM_USEMSG,onMyFunction)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyHelloView construction/destruction

CMyHelloView::CMyHelloView()

{
		m_MousePoint=" ";//初始化为空

	m_nLine=0;     //初始化

	// TODO: add construction code here

}

CMyHelloView::~CMyHelloView()
{
}

BOOL CMyHelloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyHelloView drawing

void CMyHelloView::OnDraw(CDC* pDC)
{
	CMyHelloDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->TextOut(100,100,m_MousePoint);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyHelloView printing

BOOL CMyHelloView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyHelloView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}
void CMyHelloView::onMyFunction()
{
	MessageBox("恭喜，发送成功 ！");
}
void CMyHelloView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyHelloView diagnostics

#ifdef _DEBUG
void CMyHelloView::AssertValid() const
{
	CView::AssertValid();
}

void CMyHelloView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyHelloDoc* CMyHelloView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyHelloDoc)));
	return (CMyHelloDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyHelloView message handlers

void CMyHelloView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_MousePoint.Format("鼠标左键在点(%d,%d)按下",point.x,point.y);
	Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}

void CMyHelloView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_MousePoint="鼠标左键被释放";
		Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CMyHelloView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_MousePoint.Format("鼠标位于点(%d,%d)",point.x,point.y);
	  
	    Invalidate();

	CView::OnMouseMove(nFlags, point);
}

void CMyHelloView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==VK_RETURN) //如果按下回车键
	{
		m_strDisplay.Empty();
		m_nLine++;
	}
	else
	{
		m_strDisplay +=nChar;
	}
	CClientDC dc(this);
	dc.TextOut(0,m_nLine*20,m_strDisplay);
	 
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMyHelloView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	HWND hWnd=GetSafeHwnd();
	if(nChar==VK_UP)
	{
		::PostMessage(hWnd,WM_USEMSG,0,0);
		return;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
