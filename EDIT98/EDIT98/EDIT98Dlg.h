// EDIT98Dlg.h : ͷ�ļ�
//

#pragma once


// CEDIT98Dlg �Ի���
class CEDIT98Dlg : public CDialog
{
// ����
public:
	CEDIT98Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EDIT98_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double m_num1;
	afx_msg void OnEnChangeNum1();
	afx_msg void OnBnClickedRadio3();
	int m_operator;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedRadio4();
	double m_num2;
	afx_msg void OnEnChangeEdit2();
	double m_result;
	afx_msg void OnBnClickedButton1();
};
