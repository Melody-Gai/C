// MySdiDoc.cpp : CMySdiDoc ���ʵ��
//

#include "stdafx.h"
#include "MySdi.h"

#include "MySdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMySdiDoc

IMPLEMENT_DYNCREATE(CMySdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySdiDoc, CDocument)
END_MESSAGE_MAP()


// CMySdiDoc ����/����

CMySdiDoc::CMySdiDoc()
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
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
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
