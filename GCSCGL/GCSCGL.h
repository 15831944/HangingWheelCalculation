
// GCSCGL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGCSCGLApp:
// �йش����ʵ�֣������ GCSCGL.cpp
//

class CGCSCGLApp : public CWinApp
{
public:
	CGCSCGLApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGCSCGLApp theApp;