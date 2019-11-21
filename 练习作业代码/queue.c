//ѭ������
typedef int QElemType;
typedef struct
{
    QElemType data[MAX];
    int front;
    int rear;
}SqQueue;

typedef enum Status
{
    OK;
    ERROR;
}Status;

Status initQueue(SqQueue *Q)//��ʼ��һ������
{
    Q->top=0;
    Q->rear=0;
    return OK;
}

int QueueLength(SqQueue Q)//�ж϶��г���
{
    return (Q.rear-Q.front+MAX)%MAX;
}

Status DestroyQueue(SqQueue *Q)//����һ������
{
    while(*(Q->data)!=NULL)
    {
        free(*(Q->data));
        *(Q->data)=NULL;
    }
    return OK;
}
Status ClearQueue(SqQueue *Q)//���һ������
{
   int i = Q->front;
	if (IsEmptyAQueue(Q))
	{
		return ERROR;
	}
	while (i != Q->rear)
	{
		i = 0;
		i++;
	}
	Q->front = Q->rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q)//�ж϶����Ƿ�Ϊ��
{
    if(Q->front==Q->rear)
        return OK;
    else
        return ERROR;
}

Status QueueFull(SqQueue *Q)//�ж϶����Ƿ���
{
    if((Q->rear+1)%MAX==Q->front)
        return OK;
    else
        return ERROR;
}

Status GetHead(SqQueue Q,QElemType *e)//�õ�ͷԪ��
{
   if(Q->front==Q->rear)
        return ERROR;
   *e=Q->data[Q->front];
   return *e;
}

Status EnQueue(SqQueue *Q,QElemType e)//���
{
    if((Q->rear+1)%MAX==Q->front)
        return ERROR;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAX;
    return OK;
}

Status DeQueue(SqQueue *Q,QElemType *e)//����
{
   if(Q->front==Q->rear)
        return ERROR;
   *e=Q->data[Q->front];
   Q->front=(Q->front+1);
   return OK;
}

Status TraverSqQueue(const SqQueue *Q, void(*foo)(void *q)) //������������
{
	if (QueueEmpty(SqQueue Q))
	{
		return ERROR;
	}
	(*foo)((void *)Q);
	return OK;
}

void Print(void *q)
{
	SqQueue *Q = (SqQueue *)q;
	int temp = Q->front;
	printf("�������£�");
	while (temp != Q->rear)
	{
		printf("%d\t", *(int *)(Q->data) + temp * 4);
		temp++;
	}
}
