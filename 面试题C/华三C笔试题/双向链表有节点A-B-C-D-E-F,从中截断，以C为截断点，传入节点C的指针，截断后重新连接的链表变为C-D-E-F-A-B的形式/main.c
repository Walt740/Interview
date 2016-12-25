/*
    2.����ڵ�ṹ�嶨��
    struct node{
    int data;
    struct node *prev;
    struct node *next;
    };
    �����Ѿ�������ϵ�һ��˫�������нڵ�A-B-C-D-E-F,���нضϣ���CΪ�ضϵ㣬����ڵ�C��ָ�룬
    �ضϺ��������ӵ������ΪC-D-E-F-A-B����ʽ��д��ʵ����һ���ܵ�C���Դ��룬�����������ͷ�ڵ�ָ�롣��10�֣�
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
    NODE *head = (NODE*)malloc(sizeof(NODE)); //Ϊͷָ�����붯̬�ڴ�
    head->data = 1;
    head->next = NULL;  //��ָ���ÿ�
    head->prev = NULL;  //ǰָ���ÿ�
    NODE *p = head;
    NODE *q = head;

    for(int i = 2; i < 7; i++ )
    {
        q = (NODE*)malloc(sizeof(NODE));
        q->data = i;
        p->next = q;
        q->prev = p; //q��ǰָ��ָ��ǰһ�����
        q->next = NULL;
        p = q; //pָ������ƶ�
    }
    //��ӡ�����е�data��ȷ��˫����������
    p = q = head;
    for(int i = 0; i < 6 ; i++)
    {
        printf("%d-",q->data);
        q = q->next;
    }
	printf("\n");

	//�ҵ�C(3)��㣬����ָ��ŵ�tmp head��ͬʱ��p��qָ������β
	p = head;
	q = head;
	NODE *tmp_head = head;
	while (NULL != p->next) //��pָ���Ƶ�����β���
	{
		if (3 == p->data)
		{
			tmp_head = p;
		}
		q = p->next;
		p = q;
	}
	//��A-B���Ų��F������
	p->next = head; //β����nextָ��ָ��ͷ���
	head->prev = p; //ͷ����prevָ��ָ��β���
	q = head->next; //q ָ�� B
	q->next = NULL;

	//��ӡ��ǰ������֤����Ƿ���ȷ
	p = tmp_head;
	q = tmp_head;
	for (int i = 0; i < 6; i++)
	{
		printf("%d-", p->data);
		q = p->next;
		p = q;
	}
	printf("\n");

	//�ͷ��ڴ�
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
