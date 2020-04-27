#include<windows.h>
#include<tchar.h>
#include"7_1.h"
LRESULT CALLBACK WndProc1(HWND,UINT,WPARAM,LPARAM);//窗口函数说明
//----以下初始化窗口函数----
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInst,LPSTR lpszCmdLine,int nCmdShow)
{
    WNDCLASSEX wcex;
	HWND hwnd;
	MSG Msg;
	TCHAR lpszClassName[]=L"菜单操作";//窗口类名
	TCHAR lpszTitle[]=L"菜单操作";//窗口标题名

//窗口类定义

	wcex.cbSize=sizeof(WNDCLASSEX);//窗口类型的字节数
	wcex.style=0;//窗口类型为缺省
	wcex.lpfnWndProc =WndProc1;//窗口处理函数为WndProc1
	wcex.cbClsExtra=0;//窗口类无扩展
	wcex.cbWndExtra =0;//窗口示例无扩展
	wcex.hInstance =hInstance;//当前实例句柄
	wcex.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_APPLICATION)); //窗口的最小化图标为缺省图标
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);//窗口采用箭头光标
	wcex.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//窗口背景为白色
	wcex.lpszMenuName=L"MYMENUNAME";//窗口中无菜单
	wcex.lpszClassName=lpszClassName;//窗口类名为“窗口实例”
	wcex.hIconSm=LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_APPLICATION));

//----以下进行窗口类注册----

	if(!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,_T("窗口注册失败"),_T("窗口注册"),NULL);
		return 1;
	}

//创建窗口

	hwnd=CreateWindow(
			lpszClassName,//窗口类名
			lpszTitle,//窗口实例的标题名
			WS_OVERLAPPEDWINDOW,//窗口风格
			CW_USEDEFAULT,
			CW_USEDEFAULT,//窗口左上角为缺省
			CW_USEDEFAULT,
			CW_USEDEFAULT,//窗口的高和宽为缺省值
			NULL,//此窗口无父菜单
			NULL,//此窗口无主菜单
			hInstance,//创建此窗口的应用程序的当前实例句柄
			NULL);//不使用该值
	if(!hwnd)
	{
		MessageBox(NULL,_T("窗口创建失败!"),_T("窗口创建"),NULL);
		return 1;
	}
	ShowWindow(hwnd,nCmdShow);//显示窗口
	UpdateWindow(hwnd);//绘制用户区
	HACCEL hAccel=LoadAccelerators(hInstance,L"MYMENUACCEL");
	while(GetMessage(&Msg,NULL,0,0))//消息循环
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return(int)Msg.wParam;//消息循环结束即程序终止时将信息返回系统
}

LRESULT CALLBACK WndProc1(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	HMENU hMenu,hHaddMenu;
	switch(message)
	{
	case WM_COMMAND:
			switch(LOWORD(wParam))
			{
			case IDM_ADDMENU:
				hMenu=GetMenu(hWnd);
				hHaddMenu=CreateMenu();
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_ADD,L"求和");
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_VARIANCE,L"方差");
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_AVEREAGE,L"平均值");
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_STANDARDDEVIATION,L"均方差");
				InsertMenu(hMenu,2,MF_POPUP|MF_BYPOSITION,(UINT)hHaddMenu,L"统计计算(&C)");
				EnableMenuItem(hMenu,IDM_ADDMENU,MF_GRAYED);
				EnableMenuItem(hMenu,IDM_DELMENU,MF_ENABLED);
				DrawMenuBar(hWnd);
				break;
			case IDM_DELMENU:
				hMenu=GetMenu(hWnd);
				DeleteMenu(hMenu,2,MF_BYPOSITION);
				EnableMenuItem(hMenu,IDM_DELMENU,MF_GRAYED);
				EnableMenuItem(hMenu,IDM_ADDMENU,MF_ENABLED);
				DrawMenuBar(hWnd);
				break;
			case IDM_EXIT:
				SendMessage(hWnd,WM_DESTROY,0,0);
				break;
			}
			break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd,message,wParam,lParam);
		break;
	}
return(0);
}
