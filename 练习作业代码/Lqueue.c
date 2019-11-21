#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
typedef int QElemType
typedef struct QueueNode//���ṹ
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct//��ʽ�ṹ
{
    QueuePtr front,rear;//��ͷ��βָ��
}LinkQueue;

typedef enum Status
{
    OK;
    ERROR;
}Struct;

Status initLQueue(LinkQueue *Q)//��ʼ��һ������
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->rear->next = NULL;   //rear.nextʼ��ָ��NULL,ͷ���front����
	return OK;
}

Status DestroyLQueue(LinkQueue *Q)//����һ������
{
    while (Q->front)
    {
        Q->rear=Q->rear->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue *Q)//�������Ԫ��
{
    QueuePtr *p = Q->front;
	while (p != NULL)
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
		return OK;
	}
}

Status LQueueEmpty(LinkQueue Q)//�ж϶����Ƿ�Ϊ��
{
    if(Q->front->next==NULL)
        return OK;
    else
        return ERROR;
}

Status LGetHead(LinkQueue *Q,QElemType *e)//�õ����е�ͷԪ��
{
    int data;
	data = e;
	if (Q->front == NULL)
	{
		return ERROR;
	}
	data = Q->front->data;
	return OK;
}

Status EnLQueue(LinkQueue *Q,QElemType e)//���
{
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s)
        exit(overflow_error);
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
    return OK;
}

Status DeLQueue(LinkQueue *Q,QElemType *e)//����
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return OK;
}

Status QueueLength(LinkQueue Q)//�ж϶��г���
{
    int k = 0;
	Node *f, *r;
	f = r = (QueuePtr*)malloc(sizeof(QNode));
	f = Q->front;
	r = Q->rear;
	if (r == NULL)
	{
		return 0;
	}
	else
	{
		while (f!=NULL)
		{
			k++;
			f = f->next;
		}
		return k;
	}
}
Status TraverseLQueue(const LinkQueue *Q, void(*foo)(void *q))//��������Ԫ��
{
	if (Q->rear == Q->front)
	{
		return ERROR;
	}
	QueuePtr *p = Q->front->next;
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	return OK;
}

void LPrint(void *q)
{
	QueuePtr *p;
	LinkQueue	*Q;
	Q = q;
	p = Q->front->next;
	printf("����Ϊ��\n");
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
}
