// EDIT98Dlg.h : 头文件
//

#pragma once


// CEDIT98Dlg 对话框
class CEDIT98Dlg : public CDialog
{
// 构造
public:
	CEDIT98Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EDIT98_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
