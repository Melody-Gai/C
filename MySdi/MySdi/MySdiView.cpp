// MySdiView.cpp : CMySdiView ���ʵ��
//

#include "stdafx.h"
#include "MySdi.h"

#include "MySdiDoc.h"
#include "MySdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMySdiView

IMPLEMENT_DYNCREATE(CMySdiView, CView)

BEGIN_MESSAGE_MAP(CMySdiView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMySdiView ����/����

CMySdiView::CMySdiView()
{
	// TODO: �ڴ˴���ӹ������

}

CMySdiView::~CMySdiView()
{
}

BOOL CMySdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMySdiView ����

void CMySdiView::OnDraw(CDC* /*pDC*/)
{
	CMySdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMySdiView ��ӡ

BOOL CMySdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMySdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMySdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMySdiView ���

#ifdef _DEBUG
void CMySdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMySdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMySdiDoc* CMySdiView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySdiDoc)));
	return (CMySdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMySdiView ��Ϣ�������
