
// bluetooth.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CbluetoothApp:
// �� Ŭ������ ������ ���ؼ��� bluetooth.cpp�� �����Ͻʽÿ�.
//

class CbluetoothApp : public CWinApp
{
public:
	CbluetoothApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CbluetoothApp theApp;