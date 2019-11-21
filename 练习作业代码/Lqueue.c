#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
typedef int QElemType
typedef struct QueueNode//结点结构
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct//链式结构
{
    QueuePtr front,rear;//队头队尾指针
}LinkQueue;

typedef enum Status
{
    OK;
    ERROR;
}Struct;

Status initLQueue(LinkQueue *Q)//初始化一个队列
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->rear->next = NULL;   //rear.next始终指向NULL,头结点front不动
	return OK;
}

Status DestroyLQueue(LinkQueue *Q)//销毁一个队列
{
    while (Q->front)
    {
        Q->rear=Q->rear->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue *Q)//清除队列元素
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

Status LQueueEmpty(LinkQueue Q)//判断队列是否为空
{
    if(Q->front->next==NULL)
        return OK;
    else
        return ERROR;
}

Status LGetHead(LinkQueue *Q,QElemType *e)//得到队列的头元素
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

Status EnLQueue(LinkQueue *Q,QElemType e)//入队
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

Status DeLQueue(LinkQueue *Q,QElemType *e)//出队
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

Status QueueLength(LinkQueue Q)//判断队列长度
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
Status TraverseLQueue(const LinkQueue *Q, void(*foo)(void *q))//遍历队列元素
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
	printf("队列为：\n");
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
}
