// MyHelloDoc.cpp : implementation of the CMyHelloDoc class
//

#include "stdafx.h"
#include "MyHello.h"

#include "MyHelloDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyHelloDoc

IMPLEMENT_DYNCREATE(CMyHelloDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyHelloDoc, CDocument)
	//{{AFX_MSG_MAP(CMyHelloDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyHelloDoc construction/destruction

CMyHelloDoc::CMyHelloDoc()
{
	// TODO: add one-time construction code here

}

CMyHelloDoc::~CMyHelloDoc()
{
}

BOOL CMyHelloDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyHelloDoc serialization

void CMyHelloDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyHelloDoc diagnostics

#ifdef _DEBUG
void CMyHelloDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyHelloDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyHelloDoc commands
