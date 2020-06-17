// MySdiDoc.cpp : CMySdiDoc 类的实现
//

#include "stdafx.h"
#include "MySdi.h"

#include "MySdiDoc.h"
#include "DlgInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMySdiDoc

IMPLEMENT_DYNCREATE(CMySdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySdiDoc, CDocument)
	ON_COMMAND(ID_Menu, &CMySdiDoc::OnChangetext)
END_MESSAGE_MAP()


// CMySdiDoc 构造/析构

CMySdiDoc::CMySdiDoc()
: m_str(_T(""))
{
	// TODO: 在此添加一次性构造代码

}

CMySdiDoc::~CMySdiDoc()
{
}

BOOL CMySdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMySdiDoc 序列化

void CMySdiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar<<m_str;
	}
	else
	{
		// TODO: 在此添加加载代码
		ar>>m_str;
	}
}


// CMySdiDoc 诊断

#ifdef _DEBUG
void CMySdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMySdiDoc 命令

void CMySdiDoc::OnChangetext()
{
	// TODO: 在此添加命令处理程序代码
	DlgInput dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_str = dlg.m_input;
		UpdataAllViews(NULL);
	}
}
