
// ######################################################################## //
//
//  本程序使用栈来判定回文字符串.
//
//  创建日期: 2017-04-03
//
//  修改记录:
//  ( 1 ) 2017-04-03 创建了初始版本( v0.10 )
//
//  版 本 号: v0.10
//
//  备    注: 使用标准 C 代码实现
//
//  作    者: 刘伟
//
// ######################################################################## //

// PalindromicString.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"

// 使用的库定义
#include < stdio.h >
#include < stdlib.h >
#include < string.h >

// ######################################################################## //
//                                                                          // 
//                              下面是数据定义区                               // 
//                                                                          // 
// ######################################################################## //

#define STACK_SIZE 100
#define TRUE       1
#define FALSE      0

// 顺序栈( 字符型 )的结构体类型定义 ...
typedef struct
{
  char Elem[ STACK_SIZE ];
  int  Top;
} SeqCharStack;

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                           下面是各个子函数定义                               // 
//                                                                          // 
// ######################################################################## //

// 顺序栈( 字符型 )的操作及实现 ...
void InitStack( SeqCharStack *S );
int  IsStackEmpty( SeqCharStack *S );
int  IsStackFull( SeqCharStack *S );
int  PushStack( SeqCharStack *S, char x );
int  PopStack( SeqCharStack *S, char *x );

int IsPalindromicString( char *s );

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                      下面是顺序栈( 字符型 )的操作及实现                        // 
//                                                                          // 
// ######################################################################## //

// 栈初始化 ...
void InitStack( SeqCharStack *S )
{
  S -> Top = -1;
}

// 栈是否为空 ...
int IsStackEmpty( SeqCharStack *S )
{
  return ( S -> Top == -1 );
}

// 栈是否为满 ...
int IsStackFull( SeqCharStack *S )
{
  return ( S -> Top == ( STACK_SIZE - 1 ) );
}

// 入栈 ...
// ( 本函数要求同学实现 )
int PushStack( SeqCharStack *S, char x )
{
  if (IsStackFull(S)) {
  	return 0;
  }
  S->Top++;
  S->Elem[S->Top] = x;

  return 1;
}

// 出栈 ...
// ( 本函数要求同学实现 )
int PopStack( SeqCharStack *S, char *x )
{
  if (IsStackEmpty(S)) {
  	return 0;
  }
  *x = S->Elem[S->Top];
  S->Top--;
  return 1;
}

// 利用栈判定字符串是否为回文字符串 ...
// ( 本函数要求同学实现 )
int IsPalindromicString( char *s )
{
  SeqCharStack PStrStack;
  char         x, *p;
  int          OK = TRUE;

  // '回文' 是指正读和反读都相同的字符序列. 如 'abba' 和 'abcba' 都是回文字符串.
  // 根据回文的特点, 可知利用栈可以方便地判定是否为回文. 具体方法是将待判定的字符串
  // 的每个字符依次压入栈, 出栈时( 次序为从尾至头 )依次和待判定字符串从头至尾的每个
  // 字符进行比较, 相等则表明是回文.
  //
  // 示例 :
  //
  // ( 1 ) 判定字符串 'abta' 是否为回文.
  // 入栈次序 : a b t a ( 待判定字符串从头至尾的次序 ) 
  // 出栈次序 : a t b a
  // 结   论 : 不相等, 所以不是回文
  //
  // ( 2 ) 判定字符串 'adcda' 是否为回文.
  // 入栈次序 : a d c d a ( 待判定字符串从头至尾的次序 ) 
  // 出栈次序 : a d c d a
  // 结   论 : 相等, 所以是回文

  // 栈初始化 ...
  InitStack( &PStrStack );

  // 字符压栈 ...
  p = s;
  while (*p) {
  	PushStack(&PStrStack, *p);
  	p++;
  }

  // 字符弹栈 ...
  p = s;
  while (*p) {
  	PopStack(&PStrStack, &x);
  	if (*p == x) {
  		p++;
  	} else {
  		return FALSE;
  	}
  }
  
  return OK;
}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             下面是主程序的实现                              // 
//                                                                          // 
// ######################################################################## //

void main( void )
{
  char Str[ 50 ];
  int  IsStop;

  IsStop = FALSE;
  while ( !IsStop )
  {
    printf( "\n\n\t请输入 < 待判别字符串 > ， 输入 < q / Q > 表示结束 : " );
    scanf( "%s", Str );

    if ( strlen( Str ) )
    {
	  IsStop = ( ( Str[ 0 ] == 'q' ) || ( Str[ 0 ] == 'Q' ) );
	  if ( !IsStop )
	  {
		// 判定是否为回文字符串 ...
		if ( IsPalindromicString( Str ) )
          printf( "\n\t字符串 %s 是回文字符串！\n", Str );
		else
          printf( "\n\t字符串 %s 不是回文字符串！\n", Str );
	  }
    }
    else
      printf( "输入的字符串不能为空 !\n\n" );
  }

  // 等待用户输入任意一键返回 ...
  printf( "\n\n" );
  system( "PAUSE" );
}

//////////////////////////////////////////////////////////////////////////////
