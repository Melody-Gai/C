// MySdiDoc.cpp : CMySdiDoc ���ʵ��
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


// CMySdiDoc ����/����

CMySdiDoc::CMySdiDoc()
: m_str(_T(""))
{
	// TODO: �ڴ����һ���Թ������

}

CMySdiDoc::~CMySdiDoc()
{
}

BOOL CMySdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMySdiDoc ���л�

void CMySdiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar<<m_str;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar>>m_str;
	}
}


// CMySdiDoc ���

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


// CMySdiDoc ����

void CMySdiDoc::OnChangetext()
{
	// TODO: �ڴ���������������
	DlgInput dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_str = dlg.m_input;
		UpdataAllViews(NULL);
	}
}
