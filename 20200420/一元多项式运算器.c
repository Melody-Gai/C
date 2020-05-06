
// 使用的库定义
#include < stdio.h >
#include < stdlib.h >
#include < string.h >

#define TRUE  1
#define FALSE 0

// 一元多项式采用单链表表示, 下面是链表中节点的结构体类型定义 ...
typedef struct PolyNode
{
  int Coef;              // 多项式系数 ...
  int Exp;               // 多项式指数 ...
  struct PolyNode *next; // 链接指针 ...
}PolyNode, *PolyList;

PolyList PolyA_HeadPtr; // 多项式 A( x ) 的链表头指针 ...
PolyList PolyB_HeadPtr; // 多项式 B( x ) 的链表头指针 ...

PolyList CreateEmptyPoly( PolyList Head_Ptr );
void     ClearPoly( PolyList HeadPtr );
void     DestroyPoly( PolyList HeadPtr );
void     PrintPoly( PolyList HeadPtr );
void     CreatePolyByKeyboard( PolyList HeadPtr );
void     AddPoly( PolyList PolyA_Head, PolyList PolyB_Head );

// 创建一个空多项式链表( 仅包含一个头结点 ) ...
PolyList CreateEmptyPoly( PolyList Head_Ptr )
{
  Head_Ptr = ( PolyList )malloc( sizeof( PolyNode ) );
  Head_Ptr -> next = NULL;

  return Head_Ptr;  
}

// 清除链表中的所有节点信息( 但保留头结点 ) ...
// ( 本函数要求同学实现 )
void ClearPoly( PolyList HeadPtr )
{
  PolyNode *p;

  // 指向链表
  if ( HeadPtr != NULL )
  {
    // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//
	// 请补充完成下面的代码 ...
	// ......
	//
	// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

    // 链表中仅余头结点 ...
    HeadPtr -> next = NULL;
  }
}

// 释放整个链表 ...
void DestroyPoly( PolyList HeadPtr )
{
  // 清除链表中的所有节点信息( 但保留头结点 ) ...
  ClearPoly( HeadPtr );

  // 清除头结点空间 ...
  if ( HeadPtr != NULL )
    free( HeadPtr );
}

// 打印输出一元多项式 ...
void PrintPoly( PolyList HeadPtr )
{
  PolyNode *p;

  // 多项式为空时输出 '0' ...
  if ( HeadPtr -> next == NULL )
  {
	printf( "0" );

	return;
  }

  // 指向链表
  p = HeadPtr -> next;
  while( p != NULL )
  {
	// 打印输出的结果形如 : 
	// 9x - 2x ^ 2 + 11x ^ 5
    // 1 + 3x ^ 2 - 4x ^ 7
    // -5 - x ^ 3 + 5x ^ 10
	// 1 - x - x ^ 6 + 10x ^ 9

	// 第一项符号的处理 ...
	if ( p == HeadPtr -> next ) 
	{
	  if ( p -> Coef < 0 )
	    printf( "-" );
	}0

    // 打印系数值 ...
    if ( p -> Exp == 0 ) // 处理常数项 ...
	{
	  printf( "%d", p -> Coef );
	}
	else
	{
	  if ( p -> Exp == 1 ) // 处理一次项 ...
	  {
	    if ( abs( p -> Coef ) == 1 )
		  printf( "x" );
		else
		  printf( "%dx", abs( p -> Coef ) );
	  }
	  else // 处理其他次项 ...
	  {
	    if ( abs( p -> Coef ) == 1 )
		  printf( "x ^ %d", p -> Exp );
		else
		  printf( "%dx ^ %d", abs( p -> Coef ), p -> Exp );
	  }
	}

	// 最后一项不输出分隔符 ...
	if ( p -> next != NULL ) 
	{
	  if ( p -> next -> Coef > 0 )
	    printf( " + " );
	  else
	    printf( " - " );
	}

	// 处理下一项 ...
    p = p -> next;
  }
}

// 根据用户从键盘输入的一元多项式的系数值和指数值构建链表( 指数项输入时必须由小到大 ) ...
void CreatePolyByKeyboard( PolyList HeadPtr )
{
  PolyNode *r, *s;
  char     str[ 50 ];
  int      Coef; // 多项式系数 ...
  int      Exp;  // 多项式指数 ...
  int      IsStop;

  // 清除链表中的原有数据 ...
  ClearPoly( HeadPtr );

  // 头节点指针 ...
  r = HeadPtr;

  IsStop = FALSE;
  while ( !IsStop )
  {
    printf( "\t请输入 < 多项式系数 - 整数值 > ( q 或 Q 退出 ): " );
    scanf( "%s", str );

	IsStop = ( ( str[ 0 ] == 'q' ) || ( str[ 0 ] == 'Q' ) );
    if ( !IsStop )
	{
      Coef = atoi( str ); // 字符串转换为整数 ...

      printf( "\t请输入 < 多项式指数 - 整数值 > ( q 或 Q 退出 ): " );
      scanf( "%s", str );

	  IsStop = ( ( str[ 0 ] == 'q' ) || ( str[ 0 ] == 'Q' ) );
	  if ( !IsStop )
	  {
        Exp = atoi( str ); // 字符串转换为整数 ...

        // 使用 '尾插法' 创建多项式 ...
        s = ( PolyNode * )malloc( sizeof( PolyNode ) );
        s -> Coef = Coef;
	    s -> Exp  = Exp;
        r -> next = s;
        r = s;
	  }

      printf( "\t\n" );
	}
  }

  // 整个链表创建结束( 尾插法 ) ...
  r -> next = NULL;
}

// 多项式 'A' 和 'B' 相加( 多项式链表中指数必须由小到大排列 ) ...
void AddPoly( PolyList PolyA_Head, PolyList PolyB_Head )
{
  PolyNode *p, *q, *r, *t;
  int sum;

  p = PolyA_Head -> next;
  q = PolyB_Head -> next;
  r = PolyA_Head; // 'r' 指针总是指向 'p' 的前一个节点 ...

  // 对 'B' 多项式链表中节点的处理, 要么释放掉, 要么加入 'A' 多项式链表, 所以直接将其置空 ...
  PolyB_Head -> next = NULL;

  while ( ( p != NULL ) && ( q != NULL ) )
  { 
    if ( ( p -> Exp ) < ( q -> Exp ) )
	{
      r->next = p;;
      r = r->next;
      p = p->next;

	}
    else if ( p -> Exp == q -> Exp )
    {
	  // 系数相加 ...
	  sum = p -> Coef + q -> Coef;
    if(sum != 0) {
      p->Coef = sum;
      r->next = p;
      r = r->next;
      p = p->next;
      t = q;
      q = q->next;
      free(t);
    }else {
      t = p->next;
      free(p);
      p = t;
      t = q->next;
      free(q);
      q = t;
    }
    

	}
    else // 'p -> Exp > q -> Exp' ...
	{
	  r->next = q;
    r = r->next;
    q = q->next;
		
    }
  } // end 'while ( ( p != NULL ) && ( q != NULL ) )' ...

  // 若 'B' 链表为空, 将剩下的节点链接起来 ...
  if ( p != NULL )
    r -> next = p;

  // 若 'A' 链表为空, 将剩下的节点链接起来 ...
  if ( q != NULL )
    r -> next = q;
}

void main( void )
{
  int  IsStop;
  char UserInput[ 20 ];

  // 初始化一元多项式 'A' 和 'B'( 创建头结点 ) ...
  PolyA_HeadPtr = CreateEmptyPoly( PolyA_HeadPtr );
  PolyB_HeadPtr = CreateEmptyPoly( PolyB_HeadPtr );

  IsStop = FALSE;
  while ( !IsStop )
  {
	// 输入多项式 'A' ...
    printf( "\n\n\t请输入一元多项式 A( x )， 输入的多项式指数值必须由小到大 ...\n\n" );
	CreatePolyByKeyboard( PolyA_HeadPtr );
    printf( "\n\t多项式 A( x ) = " );
	PrintPoly( PolyA_HeadPtr );
	printf( "\n\n" );
	
	// 输入多项式 'B' ...
    printf( "\n\n\t请输入一元多项式 B( x )， 输入的多项式指数值必须由小到大 ...\n\n" );
	CreatePolyByKeyboard( PolyB_HeadPtr );
    printf( "\n\t多项式 B( x ) = " );
	PrintPoly( PolyB_HeadPtr );
	printf( "\n\n" );
		
    // 多项式相加 ...
    AddPoly( PolyA_HeadPtr, PolyB_HeadPtr );
	printf( "\n\t多项式 A( x ) + B( x ) = " );
	PrintPoly( PolyA_HeadPtr );
	printf( "\n\n" );
	 
	printf( "\n\n" );
    printf( "\n\t继续处理[ Y / N ] ?" );
    scanf( "%s", UserInput );
	IsStop = ( ( UserInput[ 0 ] == 'n' ) || ( UserInput[ 0 ] == 'N' ) );
  }

  // 释放空间 ...
  DestroyPoly( PolyA_HeadPtr );
  DestroyPoly( PolyB_HeadPtr );

  // 等待用户输入任意一键返回 ...
  printf( "\n\n" );
  system( "PAUSE" );
}
