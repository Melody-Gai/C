// MySdi.h : MySdi Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMySdiApp:
// �йش����ʵ�֣������ MySdi.cpp
//

class CMySdiApp : public CWinApp
{
public:
	CMySdiApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMySdiApp theApp;