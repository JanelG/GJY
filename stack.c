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

Status InitStack(*S)//初始化一个栈
{
    S->top=NULL;
    S->count=0;
    return OK;
}

Status DestroyStack(*S)//销毁一个栈
{
    if(S->top==-1)
        return ERROR;
    free(S);
    return OK;
}

Status ClearStack(*S)//清除一个栈的元素
{
    if(S->top=-1)
        return ERROR;
    S->top=-1;
    return OK;

}

Status StackEmpty(S)//判断栈是否为空
{
    if(S->top==-1)
        return OK;
    else
        return ERROR;
}

Status GetTop(S,*e)//得到栈顶元素
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    return OK;
}

Status Push(*S,e)//元素入栈
{
    if(S->top=MAX-1)
        return ERROR;
    S->data[S->top]=e;
    S->top++;
    return OK;
}

Status Pop(*S,*e)//元素出栈
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return OK;
}

Status StackLength(S)//输出栈的长度
{
    int length;
    length=MAX-1;
    return OK;
}
