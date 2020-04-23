#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WndProc1(HWND,UINT,WPARAM,LPARAM);     //窗口函数说明

//---------------以下初始化窗口类---------------//

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR IpszCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	MSG Msg;
	TCHAR IpszClassName[]=L"窗口";      //窗口类名
	TCHAR IpszTitle[]=L"MY Windows";       //窗口标题名

	//窗口类的定义

	wcex.cbSize=sizeof(WNDCLASSEX);      //窗口类型的字节数
	wcex.style=0;     //窗口类型为缺省类型
	wcex.lpfnWndProc=WndProc1;     //窗口处理函数为WndProc
	wcex.cbClsExtra=0;      //窗口类无扩展
	wcex.cbWndExtra=0;      //窗口实例无扩展
	wcex.hInstance=hInstance;       //当前实例句柄
	wcex.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_APPLICATION));       //窗口的最小化图标为缺省图标
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);      //窗口采用箭头光标
	wcex.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);      //窗口背景为白色
	wcex.lpszMenuName=NULL;       //窗口无菜单
	wcex.lpszClassName=IpszClassName;        //窗口类名为“窗口示例”
	wcex.hIconSm=LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_APPLICATION));

//--------------以下进行窗口类的注册-------------//

	if(!RegisterClassEx(&wcex))       //如果注册失败则发出警告声音
	{
		MessageBox(NULL,_T("窗口注册失败"),_T("窗口注册"),NULL);
		return 1;
	}

	//创建窗口

	hwnd=CreateWindow(
		IpszClassName,      //窗口类名
		IpszTitle,      //窗口示例的标题名
		WS_OVERLAPPEDWINDOW,       //窗口的风格
		CW_USEDEFAULT,
		CW_USEDEFAULT,      //窗口左上角坐标为缺省值
		CW_USEDEFAULT,
		CW_USEDEFAULT,      //窗口的高和宽为缺省值
		NULL,       //此窗口无父窗口
		NULL,       //此窗口无主菜单
		hInstance,       //创建此窗口的应用程序的当前句柄
		NULL);       //不使用该值
	if(!hwnd)
	{
		MessageBox(NULL,_T("窗口创建失败！"),_T("创建窗口"),NULL);
		return 1;
	}
	ShowWindow(hwnd,nCmdShow);       //显示窗口
	UpdateWindow(hwnd);       //绘制用户区
	while(GetMessage(&Msg,NULL,0,0))       //消息循环
	{
		TranslateMessage(&Msg);      //翻译消息
		DispatchMessage(&Msg);      //分发消息
	}
	return(int)Msg.wParam;       //消息循环结束即程序终止时将信息返回系统
}
LRESULT CALLBACK WndProc1(HWND hwnd,UINT message,WPARAM wParam,LPARAM IParam)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);       //调用PostQuitMessage发出WM_QUIT消息
		break;
	default:
		return DefWindowProc(hwnd,message,wParam,IParam);
		break;
	}
	return(0);
}
