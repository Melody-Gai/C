#include<windows.h>
#include<tchar.h>
#include"7_1.h"
LRESULT CALLBACK WndProc1(HWND,UINT,WPARAM,LPARAM);//���ں���˵��
//----���³�ʼ�����ں���----
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInst,LPSTR lpszCmdLine,int nCmdShow)
{
    WNDCLASSEX wcex;
	HWND hwnd;
	MSG Msg;
	TCHAR lpszClassName[]=L"�˵�����";//��������
	TCHAR lpszTitle[]=L"�˵�����";//���ڱ�����

//�����ඨ��

	wcex.cbSize=sizeof(WNDCLASSEX);//�������͵��ֽ���
	wcex.style=0;//��������Ϊȱʡ
	wcex.lpfnWndProc =WndProc1;//���ڴ�����ΪWndProc1
	wcex.cbClsExtra=0;//����������չ
	wcex.cbWndExtra =0;//����ʾ������չ
	wcex.hInstance =hInstance;//��ǰʵ�����
	wcex.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_APPLICATION)); //���ڵ���С��ͼ��Ϊȱʡͼ��
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);//���ڲ��ü�ͷ���
	wcex.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//���ڱ���Ϊ��ɫ
	wcex.lpszMenuName=L"MYMENUNAME";//�������޲˵�
	wcex.lpszClassName=lpszClassName;//��������Ϊ������ʵ����
	wcex.hIconSm=LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_APPLICATION));

//----���½��д�����ע��----

	if(!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,_T("����ע��ʧ��"),_T("����ע��"),NULL);
		return 1;
	}

//��������

	hwnd=CreateWindow(
			lpszClassName,//��������
			lpszTitle,//����ʵ���ı�����
			WS_OVERLAPPEDWINDOW,//���ڷ��
			CW_USEDEFAULT,
			CW_USEDEFAULT,//�������Ͻ�Ϊȱʡ
			CW_USEDEFAULT,
			CW_USEDEFAULT,//���ڵĸߺͿ�Ϊȱʡֵ
			NULL,//�˴����޸��˵�
			NULL,//�˴��������˵�
			hInstance,//�����˴��ڵ�Ӧ�ó���ĵ�ǰʵ�����
			NULL);//��ʹ�ø�ֵ
	if(!hwnd)
	{
		MessageBox(NULL,_T("���ڴ���ʧ��!"),_T("���ڴ���"),NULL);
		return 1;
	}
	ShowWindow(hwnd,nCmdShow);//��ʾ����
	UpdateWindow(hwnd);//�����û���
	HACCEL hAccel=LoadAccelerators(hInstance,L"MYMENUACCEL");
	while(GetMessage(&Msg,NULL,0,0))//��Ϣѭ��
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return(int)Msg.wParam;//��Ϣѭ��������������ֹʱ����Ϣ����ϵͳ
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
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_ADD,L"���");
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_VARIANCE,L"����");
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_AVEREAGE,L"ƽ��ֵ");
				AppendMenu(hHaddMenu,MF_ENABLED,IDM_STANDARDDEVIATION,L"������");
				InsertMenu(hMenu,2,MF_POPUP|MF_BYPOSITION,(UINT)hHaddMenu,L"ͳ�Ƽ���(&C)");
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
