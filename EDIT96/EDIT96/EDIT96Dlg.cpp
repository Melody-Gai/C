// EDIT96Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EDIT96.h"
#include "EDIT96Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CEDIT96Dlg 对话框




CEDIT96Dlg::CEDIT96Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEDIT96Dlg::IDD, pParent)
	, m_num1(0)
	, m_operator(0)
	, m_num2(0)
	, m_result(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEDIT96Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Radio(pDX, IDC_ADD, m_operator);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_result);
}

BEGIN_MESSAGE_MAP(CEDIT96Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT1, &CEDIT96Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_ADD, &CEDIT96Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CEDIT96Dlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CEDIT96Dlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CEDIT96Dlg::OnBnClickedDiv)
	ON_EN_CHANGE(IDC_EDIT2, &CEDIT96Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_RESET, &CEDIT96Dlg::OnBnClickedReset)
END_MESSAGE_MAP()


// CEDIT96Dlg 消息处理程序

BOOL CEDIT96Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEDIT96Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEDIT96Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEDIT96Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEDIT96Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	switch(m_operator )
	{
	case 0:
		m_result=m_num1 + m_num2;
		break;
	case 1:
		m_result=m_num1 - m_num2;
		break;
	case 2:
		m_result=m_num1*m_num2 ;
		break;
	case 3:
		m_result= m_num1/m_num2;
		break;
	}
	UpdateData(FALSE);
	}



}

void CEDIT96Dlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	OnEnChangeNum1();
}

void CEDIT96Dlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
	OnEnChangeNum1();
}

void CEDIT96Dlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	OnEnChangeNum1();
}

void CEDIT96Dlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	OnEnChangeNum1();
}

void CEDIT96Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	OnEnChangeNum1();
}

void CEDIT96Dlg::OnBnClickedReset()
{
	// TODO: 在此添加控件通知处理程序代码
	m_result=m_num1=m_num2=m_operator=0;
	UpdateData(FALSE);
}
