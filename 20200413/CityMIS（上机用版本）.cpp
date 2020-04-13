
// ######################################################################## //
//
//  ������ʹ��˳���ʵ�ֳ��м�¼���ݵĹ���.
//
//  ��������: 2017-03-25
//
//  �޸ļ�¼:
//  ( 1 ) 2017-03-25 �����˳�ʼ�汾( v0.10 )
//
//  �� �� ��: v0.10
//
//  ��    ע: ʹ�ñ�׼ C ����ʵ��
//
//  ��    ��: ��ΰ
//
// ######################################################################## //

// CityMIS.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"

// ʹ�õĿⶨ��
#include < stdio.h >
#include < stdlib.h >
#include < string.h >

// ######################################################################## //
//                                                                          // 
//                              ���������ݶ�����                               // 
//                                                                          // 
// ######################################################################## //

#define MAX_CITY_NUM 100
#define TRUE  1
#define FALSE 0

// �ýṹ�嶨�����������Ϣ ...
typedef struct
{
  int   ID;         // ����Ψһ���( �ڲ�ʹ�� )
  char  Name[ 20 ]; // ��������
  float Area;       // ���( ƽ������ )
  float Population; // �˿�( �� )
  float GDP;        // ����������ֵ( ��Ԫ )
} CityRecord;

// �ýṹ�嶨����Ʒ��Ϣ
typedef struct
{
  CityRecord DataArray[ MAX_CITY_NUM ]; // ��������( ˳��� )���������Ϣ( �ṹ������ ) ...
  int        MaxID;                     // ÿ�����м�¼��Ψһ 'ID' ��, ���ڼ�¼������, ɾ, ���Ա��붯̬ά�����ֵ ...
  int        Len;                       // ��ǰ���м�¼���� ...
} CityList;

// ######################################################################## //
//                                                                          // 
//                            �����Ǹ�����������                               // 
//                                                                          // 
// ######################################################################## //

void InitCityList( CityList *L );
int  AddCity( CityList *L, CityRecord ARecord );
int  InsertCity( CityList *L, int k, CityRecord ARecord );
int  DeleteCity( CityList *L, int k );
int  FindCityByName( CityList *L, char *s );
void CalcCityStatistic( CityList *L );
void InputCityData( CityList *L );
void DisplayCityList( CityList *L );

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                           �����Ǹ���������ʵ��                               // 
//                                                                          // 
// ######################################################################## //

// ˳����ʼ�� ...
void InitCityList( CityList *L )
{
  L -> MaxID = 0;
  L -> Len   = -1;
}

// ���µĳ��м�¼���뵽˳���β ...
int AddCity( CityList *L, CityRecord ARecord )
{
  int OK = TRUE;

  if ( L -> Len == ( MAX_CITY_NUM - 1 ) )
    OK = FALSE;
  else
  {
    L -> Len++;
	L -> DataArray[ L -> Len ] = ARecord;
  }

  return OK;
}

// ���µĳ��м�¼���뵽˳����е� 'k' ��λ�ô� ...
int InsertCity( CityList *L, int k, CityRecord ARecord )
{
  int i, OK = TRUE;

  // ��������Ƿ����� ...
  if ( L -> Len >= ( MAX_CITY_NUM - 1 ) )
    OK = FALSE;
  else if ( ( k < 0 ) || ( k > L -> Len ) ) // ������λ���Ƿ���� ...
    OK = FALSE;
  else
  {
	  L -> Len++;

	  for(i = L -> Len - 1; i >= k; i--) 
	  {
		  L -> DataArray[ i + 1 ] = L -> DataArray[ i ];
	  }

	  L -> DataArray[ k ] = ARecord;

  }

  return OK;
}

// ��˳����е� 'k' ��λ�ô�Ԫ��ɾ�� ...
int DeleteCity( CityList *L, int k )
{
  int i, OK = TRUE;

  // ���ɾ��λ���Ƿ���� ...
  if ( ( k < 0 ) || ( k > L -> Len ) ) 
    OK = FALSE;
  else
  {

    

	  for(i = k ; i < L -> Len; i++) 
	  {
		  L -> DataArray[ i ] = L -> DataArray[ i + 1 ];
	  }

	  L -> Len--;

  }

  return OK;
}

// ���ݳ������Ʋ��ҳ��м�¼( ��������˳����е���� ) ...
int FindCityByName( CityList *L, char *s )
{
  int i;

  if ( strlen( s ) ) // ����ĳ������Ʋ���Ϊ�� ...
  {

    for(i = 0; i <= L -> Len; i++)
	{
		if(!strcmp(s,L -> DataArray[ i ].Name))
		{
			return  i ;
		}
	}
  }

  return -1;
}

// �������ͳ��ָ�� ...
void CalcCityStatistic( CityList *L )
{
  int i;
  float TotalArea = 0.0, TotalPopulation = 0.0, TotalGDP = 0.0;

  printf( "\n\n" );

  // ͳ�����г��е� '���( ƽ������ )', '�˿�( �� )', �� '����������ֵ( ��Ԫ )' ƽ��ֵ ...
  if ( L -> Len >= 0 )
  {

	  for(i = 0;i <= L -> Len; i++) 
	  {
		  TotalArea += L -> DataArray[ i ].Area;
		  TotalPopulation += L -> DataArray[ i ].Population;
		  TotalGDP += L -> DataArray[ i ].GDP;
	  }

  
	// ��ӡ���ͳ�ƽ�� ...
	printf( "\t< ����ƽ�� ��� Ϊ : %.2f ( ƽ������ )>\n", ( TotalArea / ( L -> Len + 1 ) ) );
	printf( "\t< ����ƽ�� �˿� Ϊ : %.2f ( �� )>\n", ( TotalPopulation / ( L -> Len + 1 ) ) );
	printf( "\t< ����ƽ�� GDP Ϊ : %.2f ( ��Ԫ )>\n", ( TotalGDP / ( L -> Len + 1 ) ) );
  }
  else
	printf( "\tû�г������� !\n" );
}

// ¼��������� ...
void InputCityData( CityList *L )
{
  CityRecord ARecord;
  int        IsStop;

  // ��ʼ�� ...
  ARecord.ID = 0;

  printf( "\n" );

  IsStop = FALSE;
  while( !IsStop )
  {
    printf( "\n" );
	printf( "\t������ < �������� > ( 'q'/'Q' �˳� ) : " );
	scanf( "%s", ARecord.Name );
	if ( ( ARecord.Name[ 0 ] == 'q' ) || ( ARecord.Name[ 0 ] == 'Q' ) ) // ���� 'q | Q' ��ʾ���� ...
	  IsStop = TRUE;
	else
	{
      printf( "\t������ < �������( ƽ������ ) > : " );
      scanf( "%f", &ARecord.Area );

      printf( "\t������ < �����˿�( �� ) > : " );
      scanf( "%f", &ARecord.Population );

      printf( "\t������ < GDP( ��Ԫ ) > : " );
      scanf( "%f", &ARecord.GDP );

      // �Զ�ά������ 'Max ID' ��, ��ͬʵ�ʵ����ݿ����ϵͳ( DBMS )һ�� ...
      L -> MaxID++;
      ARecord.ID = L -> MaxID;

	  // ��������ĩβ ...
      if ( !AddCity( L, ARecord ) )
	  {
		printf( "\n\n\t", "�����б�����, �޷������³������� !" );
		
		system( "PAUSE" );
	  }
	}
  }
}

// ��ʾ��������б� ...
void DisplayCityList( CityList *L )
{
  int i;

  printf( "\n\n" );

  if ( L -> Len >= 0 )
  {
    printf( "\t< Max ID = > %d\n", L -> MaxID );
	printf( "\t< Len    = > %d\n\n", L -> Len );
	  
	printf( "\t----------------------------------------------------------------------\n" );
    printf( "\t ���  ID   ����      ���( ƽ������ )   �˿�( �� )     GDP( ��Ԫ )\n" );
    printf( "\t----------------------------------------------------------------------\n" );

    for ( i = 0; i <= L -> Len; i++ )
	{
      printf( "\t %d", i );
	  printf( "     %d", L -> DataArray[ i ].ID );
	  printf( "     %s", L -> DataArray[ i ].Name );
	  printf( "        %.2f", L -> DataArray[ i ].Area );
	  printf( "        %.2f", L -> DataArray[ i ].Population );
      printf( "        %.2f\n", L -> DataArray[ i ].GDP );		
	}

	printf( "\t----------------------------------------------------------------------\n" );
  }
  else
	printf( "û�г������� !\n" );
}

//////////////////////////////////////////////////////////////////////////////

// ######################################################################## //
//                                                                          // 
//                             �������������ʵ��                              // 
//                                                                          // 
// ######################################################################## //

void main( void )
{
  CityList   BigCityList; // ˳���ṹ�ĳ������� ...
  CityRecord ARecord;     // �������ݽṹ�� ...
  int        k;
  char       s[ 20 ];

  // ˳����ʼ�� ...
  InitCityList( &BigCityList );

  // �û�ͨ����������������� ...
  InputCityData( &BigCityList );

  // ��ʾ�����б� ...
  DisplayCityList( &BigCityList );

  // ------------------------------------------------------------
  //
  // ������м�¼ ...
  //
  // ------------------------------------------------------------

  printf( "\n\n\t������ < ����������λ�� > : " ); // �㷨�����ǻ���λ�� '0', �û�����ʱ����λ�� '1' ...
  scanf( "%d", &k );
  if ( k >= 1 )
	k--;

  // ��ʼ�� ...
  ARecord.ID = 0;

  printf( "\n\n" );

  printf( "\t������ < �������� > : " );
  scanf( "%s", ARecord.Name );

  printf( "\t������ < �������( ƽ������ ) > : " );
  scanf( "%f", &ARecord.Area );

  printf( "\t������ < �����˿�( �� ) > : " );
  scanf( "%f", &ARecord.Population );

  printf( "\t������ < GDP( ��Ԫ ) > : " );
  scanf( "%f", &ARecord.GDP );

  // �Զ�ά������ 'Max ID' ��, ��ͬʵ�ʵ����ݿ����ϵͳ( DBMS )һ�� ...
  BigCityList.MaxID++;
  ARecord.ID = BigCityList.MaxID;
  if ( !InsertCity( &BigCityList, k, ARecord ) )
    printf( "\n\n\t", "�����б�����, �޷������³������� !" );

  // ��ʾ�����б� ...
  DisplayCityList( &BigCityList );

  // ------------------------------------------------------------
  //
  // ɾ�����м�¼ ...
  //
  // ------------------------------------------------------------

  printf( "\n\n\t������ < ɾ������λ�� > : " ); // �㷨ɾ���ǻ���λ�� '0', �û�����ʱ����λ�� '1' ...
  scanf( "%d", &k );
  if ( k >= 1 )
	k--;

  if ( DeleteCity( &BigCityList, k ) )
	printf( "\n\n\tɾ�����ݳɹ� !" );
  else
	printf( "\n\n\tɾ������ʧ�� !" );

  // ��ʾ�����б� ...
  DisplayCityList( &BigCityList );

  // ------------------------------------------------------------
  //
  // ���ҳ��м�¼ ...
  //
  // ------------------------------------------------------------

  printf( "\n\n\t������ < �����ҳ������� > : " );
  scanf( "%s", s );

  k = FindCityByName( &BigCityList, s );
  if ( k >= 0 )
  {
	printf( "\n\n\t�����������ҵ�, ��Ϣ���� : \n" );
	printf( "\t< �������� >            : %s\n", BigCityList.DataArray[ k ].Name );
    printf( "\t< �������( ƽ������ ) > : %.2f\n", BigCityList.DataArray[ k ].Area );
    printf( "\t< �����˿�( �� ) >      : %.2f\n", BigCityList.DataArray[ k ].Population );
    printf( "\t< GDP( ��Ԫ ) >        : %.2f\n\n\n", BigCityList.DataArray[ k ].GDP );
  }
  else
    printf( "\n\n\tδ�ҵ��������� !" );

  // ��ʾ����ͳ������ ...
  CalcCityStatistic( &BigCityList );

  // �ȴ��û���������һ������ ...
  printf( "\n\n" );
  system( "PAUSE" );
}

//////////////////////////////////////////////////////////////////////////////
