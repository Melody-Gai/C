#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXCAR 60  //�����г���
#define MIN_PER_HR 60.0
#define true 1
#define false 0

typedef struct item
{
	long Arrive;
	int BordingTime;
}Item;

typedef struct node
{
	Item item;
	struct node * Next;
}Node;

typedef struct queue
{
	Node * front;
	Node * rear;
	int items;
}Queue;

void InitializeQueue(Queue * pq);
int QueueIsFull(const Queue * pq);
int QueueIsEmpty(const Queue * pq);
int QueueItemCount(const Queue * pq);
int EnQueue(Item item, Queue * pq);
int DeQueue(Item * pitem, Queue * pq);
void EmptyTheQueue(Queue * pq);
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);
int NewCar(double x);
Item Cartime(long when);
double Average(double Ave[], int n);

int main(void)
{
	Queue Line;
	Item Temp;
	double Hours;//ģ��Сʱ��
	int Perhour;//ÿСʱƽ�������������⳵
	int Cycle;
	double CycleLimit;
	long TurnAway = 0;//������������ܾ��ĳ��⳵����
	long Cars = 0;//������еĹ˿�����
	long Served = 0;//��ģ��ʱ��νӵ��˿͵س��⳵����
	long SumLine = 0;//�ۻ��Ķ����ܳ�
	int WaiTime =0;//��ǰ����һ�����ؿͳ�����ʱ��
	double MinPerCars;//���⳵������ƽ��ʱ��
	long SumLineWait = 0;//�����ۻ��ĵȴ�ʱ��
	int t, tt;
	double Ave[1000] = {0};
	double SumAv[1000] = {0};
	puts("������ģ���������Ҫ����1000�Σ�:");
	scanf("%d", &t);
	tt= t;//ttΪѭ������
	puts("������ģ��ʱ��:");
	scanf("%lf", &Hours);
	puts("������ƽ��ÿСʱ�������Ŷӵĳ��⳵����:");
	scanf("%d", &Perhour);
	srand((unsigned int)time(0));
	while (tt--)//ģ�⿪ʼ
	{
		Cars = 0; Served= 0; SumLine = 0;
		TurnAway = 0; WaiTime = 0;SumLineWait = 0;
		InitializeQueue(&Line);
		CycleLimit= MIN_PER_HR * Hours * 60;
		MinPerCars =(MIN_PER_HR*60)/Perhour;
		for (Cycle = 0;Cycle<CycleLimit; Cycle++)
		{
			if (NewCar(MinPerCars))
			{
				if (QueueIsFull(&Line))
					TurnAway++;
				else
				{
					Cars++;
					Temp = Cartime(Cycle);
					EnQueue(Temp, &Line);
				}
			}
			if (WaiTime<=0 && !QueueIsEmpty(&Line))
			{
				DeQueue(&Temp, &Line);
				WaiTime = Temp.BordingTime;
				SumLineWait += Cycle - Temp.Arrive;
				Served++;
			}
			if (WaiTime > 0)
				WaiTime--;
			SumLine += QueueItemCount(&Line);
		}
		if (Cars > 0)
		{
			printf("-------------------\n");
			printf("%-40s%-15ld\n","�����Ŷӵĳ��⳵����������: ", Cars);
			printf("%-40s%-15ld\n","�ӵ��˿͵ĳ��⳵����������: ", Served);
			printf("%-40s%-15ld\n","���ڳ������ƾܾ��ĳ��⳵����������: ",TurnAway);
			printf("%-40s%.2f\n","���⳵ƽ���ȴ�ʱ�䣨�룩:",(double)SumLineWait / Served);
		}
		else
			printf("No Cars!");
		Ave[tt] = (double)SumLineWait /Served;
		SumAv[tt] = Cars;
		EmptyTheQueue(&Line);
		printf("\n");
	}
	printf("------------------\n");
	printf("%d ��ģ����⳵�ȴ�ʱ��ƽ��ֵΪ%.2f���ӣ������Ŷӳ��⳵��"
		"(%. 2f��Сʱ��ƽ����Ϊ%.2f��", t, Average(Ave, t)/60, Hours, Average(SumAv, t));
	getchar();
	getchar();
	return 0;
};

int NewCar(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item Cartime(long when)
{
	Item cust;
//cust.BordingTime= (rand() % 3 +1)* 60;
	cust.BordingTime = 90;
	cust.Arrive = when;

	return cust;
}

void InitializeQueue(Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items= 0;
}

int QueueIsFull(const Queue * pq)
{
	return pq->items == MAXCAR;
}

int QueueIsEmpty(const Queue * pq)
{
	return pq->items==0;
}

int QueueItemCount (const Queue * pq)
{
	return pq->items;
}

int EnQueue(Item item, Queue * pq)
{
	Node * pnew;
	if (QueueIsFull (pq))
		return false;
	pnew = (Node *)malloc(sizeof(Node));
  	if(pnew == NULL)
	{
		fprintf(stderr, "Unble to allocate memory\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->Next =NULL;
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else
		pq->rear->Next = pnew;
	pq->rear= pnew;
	pq->items++;
	return true;
}

int DeQueue(Item * pitem, Queue * pq)
{
	Node * pt;
	if (QueueIsEmpty(pq))
		return false;
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->Next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
		pq->rear=NULL;
	return true;
}

void EmptyTheQueue(Queue * pq)
{
	Item dummy;
	while (!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node * pq)
{
	pq->item=item;
}

static void CopyToItem(Node*pq, Item* pi)
{
	*pi=pq->item;
}

double Average(double Ave[], int n)
{
	int i;
	double Sum = 0.0;
	for (i = 0; i<=n - 1; i++)
	{
		Sum +=Ave[i];
	}
	return Sum/n;
}



