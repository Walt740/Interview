/*
    2.链表节点结构体定义
    struct node{
    int data;
    struct node *prev;
    struct node *next;
    };
    假设已经构建完毕的一个双向链表有节点A-B-C-D-E-F,从中截断，以C为截断点，传入节点C的指针，
    截断后重新连接的链表变为C-D-E-F-A-B的形式，写出实现这一功能的C语言代码，返回新链表的头节点指针。（10分）
*/

#include <stdio.h>
#include <stdlib.h>

typedef
struct node
{
    int data;
    struct node *prev;
    struct node *next;

}NODE;

int
main()
{
    NODE *head = (NODE*)malloc(sizeof(NODE)); //为头指针申请动态内存
    head->data = 1;
    head->next = NULL;  //后指针置空
    head->prev = NULL;  //前指针置空
    NODE *p = head;
    NODE *q = head;

    for(int i = 2; i < 7; i++ )
    {
        q = (NODE*)malloc(sizeof(NODE));
        q->data = i;
        p->next = q;
        q->prev = p; //q的前指针指向前一个结点
        q->next = NULL;
        p = q; //p指针向后移动
    }
    //打印链表中的data，确认双向链表生成
    p = q = head;
    for(int i = 0; i < 6 ; i++)
    {
        printf("%d-",q->data);
        q = q->next;
    }
	printf("\n");

	//找到C(3)结点，并把指针放到tmp head，同时把p，q指向链表尾
	p = head;
	q = head;
	NODE *tmp_head = head;
	while (NULL != p->next) //将p指针移到链表尾结点
	{
		if (3 == p->data)
		{
			tmp_head = p;
		}
		q = p->next;
		p = q;
	}
	//把A-B结点挪到F结点后面
	p->next = head; //尾结点的next指针指向头结点
	head->prev = p; //头结点的prev指针指向尾结点
	q = head->next; //q 指向 B
	q->next = NULL;

	//打印当前链表，验证结果是否正确
	p = tmp_head;
	q = tmp_head;
	for (int i = 0; i < 6; i++)
	{
		printf("%d-", p->data);
		q = p->next;
		p = q;
	}
	printf("\n");

	//释放内存
	p = q = tmp_head;
	for (int i = 0; i < 6; i++)
	{
		q = p->next;
		free(p);
		p = q;
	}
	p = q = head = tmp_head = NULL;

    return 0;
}
