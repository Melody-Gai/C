/*#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WndProc1(HWND,UINT,WPARAM,LPARAM);     //���ں���˵��

//---------------���³�ʼ��������---------------//

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR IpszCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	MSG Msg;
	TCHAR IpszClassName[]=L"����";      //��������
	TCHAR IpszTitle[]=L"MY Windows";       //���ڱ�����

	//������Ķ���

	wcex.cbSize=sizeof(WNDCLASSEX);      //�������͵��ֽ���
	wcex.style=0;     //��������Ϊȱʡ����
	wcex.lpfnWndProc=WndProc1;     //���ڴ�����ΪWndProc
	wcex.cbClsExtra=0;      //����������չ
	wcex.cbWndExtra=0;      //����ʵ������չ
	wcex.hInstance=hInstance;       //��ǰʵ�����
	wcex.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_APPLICATION));       //���ڵ���С��ͼ��Ϊȱʡͼ��
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);      //���ڲ��ü�ͷ���
	wcex.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);      //���ڱ���Ϊ��ɫ
	wcex.lpszMenuName=NULL;       //�����޲˵�
	wcex.lpszClassName=IpszClassName;        //��������Ϊ������ʾ����
	wcex.hIconSm=LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_APPLICATION));

//--------------���½��д������ע��-------------//

	if(!RegisterClassEx(&wcex))       //���ע��ʧ���򷢳���������
	{
		MessageBox(NULL,_T("����ע��ʧ��"),_T("����ע��"),NULL);
		return 1;
	}

	//��������

	hwnd=CreateWindow(
		IpszClassName,      //��������
		IpszTitle,      //����ʾ���ı�����
		WS_OVERLAPPEDWINDOW,       //���ڵķ��
		CW_USEDEFAULT,
		CW_USEDEFAULT,      //�������Ͻ�����Ϊȱʡֵ
		CW_USEDEFAULT,
		CW_USEDEFAULT,      //���ڵĸߺͿ�Ϊȱʡֵ
		NULL,       //�˴����޸�����
		NULL,       //�˴��������˵�
		hInstance,       //�����˴��ڵ�Ӧ�ó���ĵ�ǰ���
		NULL);       //��ʹ�ø�ֵ
	if(!hwnd)
	{
		MessageBox(NULL,_T("���ڴ���ʧ�ܣ�"),_T("��������"),NULL);
		return 1;
	}
	ShowWindow(hwnd,nCmdShow);       //��ʾ����
	UpdateWindow(hwnd);       //�����û���
	while(GetMessage(&Msg,NULL,0,0))       //��Ϣѭ��
	{
		TranslateMessage(&Msg);      //������Ϣ
		DispatchMessage(&Msg);      //�ַ���Ϣ
	}
	return(int)Msg.wParam;       //��Ϣѭ��������������ֹʱ����Ϣ����ϵͳ
}

//���ں���

LRESULT CALLBACK WndProc1(HWND hWnd,UINT message,WPARAM wParam,LPARAM IParam)
{
	HDC hDC;       //�����豸�������
	PAINTSTRUCT ptStr;       //�豸������Ҫ�İ�����Ч���εı���
	HPEN hPen;       //����
	static int MouseSign=0;      //�Ƿ����������ı�־
		switch(message)
		{
			case WM_LBUTTONDOWN:      //�ж��Ƿ��������������ñ�־
				MouseSign=1;
				InvalidateRect(hWnd,NULL,TRUE);      //�ػ�ͻ���
				break;
			case WM_PAINT:     //Ĭ���������
				hDC=BeginPaint(hWnd,&ptStr);       //�õ��豸����
				hPen=CreatePen(PS_SOLID,2,RGB(255,0,0));     //������ɫ����
				SelectObject(hDC,hPen);
				MoveToEx(hDC,10,10,NULL);   LineTo(hDC,20,70);    //��ֱ�ߣ���д����
			Ellipse(hDC,50,50,150,150);    //��Բ���Լ���������Ĳ���������д�������������������
			if(MouseSign==1)
				Rectangle(hDC,200,225,300,320);      //�����Σ��Լ������
			EndPaint(hWnd,&ptStr);
			break;
			case WM_DESTROY:
				PostQuitMessage(0);       //����PostQuitMessage����WM_QUIT��Ϣ
				break;
			default:     //ȱʡʱ����ϵͳ��Ϣȱʡ������
				return DefWindowProc(hWnd,message,wParam,IParam);
				break;
		}
		return(0);
}
*/