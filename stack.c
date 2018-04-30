typedef int SElemType;
typedef struct
{
   SElemType data[MAX];
   int top;
}SqStack;

typedef enum Status
{
    OK;
    ERROR;
}Status;

Status InitStack(*S)//��ʼ��һ��ջ
{
    S->top=NULL;
    S->count=0;
    return OK;
}

Status DestroyStack(*S)//����һ��ջ
{
    if(S->top==-1)
        return ERROR;
    free(S);
    return OK;
}

Status ClearStack(*S)//���һ��ջ��Ԫ��
{
    if(S->top=-1)
        return ERROR;
    S->top=-1;
    return OK;

}

Status StackEmpty(S)//�ж�ջ�Ƿ�Ϊ��
{
    if(S->top==-1)
        return OK;
    else
        return ERROR;
}

Status GetTop(S,*e)//�õ�ջ��Ԫ��
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    return OK;
}

Status Push(*S,e)//Ԫ����ջ
{
    if(S->top=MAX-1)
        return ERROR;
    S->data[S->top]=e;
    S->top++;
    return OK;
}

Status Pop(*S,*e)//Ԫ�س�ջ
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return OK;
}

Status StackLength(S)//���ջ�ĳ���
{
    int length;
    length=MAX-1;
    return OK;
}
