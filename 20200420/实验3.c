#include<windows.h>
#include<tchar.h>
#include<stdlib.h>
#include<string.h>
LRESULT CALLBACK wndProcl(HWND,UINT,WPARAM,LPARAM);  //窗口函数说明
//以下初始化窗口类
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInst,LPSTR 
	IpszCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	MSG Msg;

	TCHAR IpszClassName[] = L"窗口";  //窗口类名
	TCHAR IpszTitle[] = L"My windows";  //窗口标题名

	//窗口类的定义
	wcex.cbSize = sizeof(WNDCLASSEX);  //窗口类型的字节数
	wcex.style = 0;
	wcex.IpfnWndProc = wndProcl;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL,IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.IpszMenuName = NULL;
	wcex.IpszClassName = IpszClassName;

	wcex.hIconSm = LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_APPLICATION));

	if(!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,_T("窗口注册失败"),_T("窗口注册"),NULL);
		return l;
	}
	hwnd = CreatWindow(
		IpszClassName,
		IpszTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	if(!hwnd)
	{
		MessageBox(NULL,_T("窗口创建失败！"),_T("创建窗口"),NULL);
		return l;
	}
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	while(GetMessage(&Msg,NULL,0,0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return (int)Msg.wParam;
}

LRESULT CALLBACK WinProcl(HWND hwnd,UINT message, WPARAM wParam,LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd,message,wParam,lParam);
			break;
	}
	return (0);
}