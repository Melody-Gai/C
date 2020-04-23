/*#include <windows.h>
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

//窗口函数

LRESULT CALLBACK WndProc1(HWND hWnd,UINT message,WPARAM wParam,LPARAM IParam)
{
	HDC hDC;       //定义设备环境句柄
	PAINTSTRUCT ptStr;       //设备环境需要的包含无效矩形的变量
	HPEN hPen;       //画笔
	static int MouseSign=0;      //是否按下鼠标左键的标志
		switch(message)
		{
			case WM_LBUTTONDOWN:      //判断是否按下鼠标左键，设置标志
				MouseSign=1;
				InvalidateRect(hWnd,NULL,TRUE);      //重绘客户区
				break;
			case WM_PAINT:     //默认输出内容
				hDC=BeginPaint(hWnd,&ptStr);       //得到设备环境
				hPen=CreatePen(PS_SOLID,2,RGB(255,0,0));     //创建红色画笔
				SelectObject(hDC,hPen);
				MoveToEx(hDC,10,10,NULL);   LineTo(hDC,20,70);    //画直线，填写参数
			Ellipse(hDC,50,50,150,150);    //画圆，自己计算所需的参数，并填写按下鼠标左键输出的内容
			if(MouseSign==1)
				Rectangle(hDC,200,225,300,320);      //画矩形，自己填参数
			EndPaint(hWnd,&ptStr);
			break;
			case WM_DESTROY:
				PostQuitMessage(0);       //调用PostQuitMessage发出WM_QUIT消息
				break;
			default:     //缺省时采用系统消息缺省处理函数
				return DefWindowProc(hWnd,message,wParam,IParam);
				break;
		}
		return(0);
}
*/