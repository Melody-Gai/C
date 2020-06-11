// MySdiView.cpp : CMySdiView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMySdiView 构造/析构

CMySdiView::CMySdiView()
{
	// TODO: 在此处添加构造代码

}

CMySdiView::~CMySdiView()
{
}

BOOL CMySdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMySdiView 绘制

void CMySdiView::OnDraw(CDC* /*pDC*/)
{
	CMySdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMySdiView 打印

BOOL CMySdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMySdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMySdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMySdiView 诊断

#ifdef _DEBUG
void CMySdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMySdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMySdiDoc* CMySdiView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySdiDoc)));
	return (CMySdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMySdiView 消息处理程序
