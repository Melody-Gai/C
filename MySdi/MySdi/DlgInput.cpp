// DlgInput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySdi.h"
#include "DlgInput.h"


// DlgInput �Ի���

IMPLEMENT_DYNAMIC(DlgInput, CDialog)

DlgInput::DlgInput(CWnd* pParent /*=NULL*/)
	: CDialog(DlgInput::IDD, pParent)
	, m_input(_T(""))
{

}

DlgInput::~DlgInput()
{
}

void DlgInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
}


BEGIN_MESSAGE_MAP(DlgInput, CDialog)
END_MESSAGE_MAP()


// DlgInput ��Ϣ�������
