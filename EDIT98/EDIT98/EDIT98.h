// EDIT98.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEDIT98App:
// �йش����ʵ�֣������ EDIT98.cpp
//

class CEDIT98App : public CWinApp
{
public:
	CEDIT98App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEDIT98App theApp;