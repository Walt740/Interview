#include <stdio.h>
#include <stdlib.h>
//void getmemory(char *p )
//{
//	p = (char*)malloc(100);
//
//}

//char *GetMemory(void)
//{
//	char p[] = "hello world";  //函数调用完毕即释放内容
//	return p; //p 将指向一个垃圾值
//}


void  GetMemory(char **p, int num)
{
	*p = (char*)malloc(num);
}

//void Test(void)
//{
//	char *str = NULL;  
//    GetMemory(&str,100);
//	strcpy(str, "hello");
//	printf( str);
//	free(str);
//}


//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str,"hello");
//	//printf(str);
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str,"world");
//		printf(str);
//	}
//}

//struct
//{
//	char a;
//	int b;
//	short c;
//} d;


//typedef
//union
//{
//	int ia;
//	char c[4];
//	short int s[2];
//
//}untest;
//
//untest un;


#include "a.h"

int main()
{

	a = 10;
	//char * p = "yinhao";
	//printf(p );
	//Test();
	
	//printf("%d",sizeof(d));
	//un.c[0] = 0xAA;
	//un.c[1] = 0xBB;
	//un.c[2] = 0xCC;
	//un.c[3] = 0xDD;
	//printf("Ox%x\n",un.ia);
	//printf("Ox%x", un.s[0]);

	//char a[8] = {1,2,3,4,5,6,7,8};
	//int *ptr = (int*)a;
	//printf("%d,%d",*(ptr));

	//int *p = (int*)0x67a9;
	//*p = 0xaa66;


	return 0;
}