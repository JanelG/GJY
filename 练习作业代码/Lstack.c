typedef int ElemType;
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack
{
    LinkStack top;
    int count;
}LinkStack;
typedef enum Status
{
    OK;
    ERROR;
}Status;

Status initLstack(LinkStack *S)//初始化一个栈
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->next=NULL;
    S->top=S;
    return OK;
}

Status LstackEmpty(LinkStack *S)//判断栈是否为空
{
    if(S->top==NULL)
        return OK;
    else
        return ERROR;
}

Status ClearLstack(LinkStack *S)//清除一个栈的元素
{
    if(S->top==NULL)
        return OK;
    S->top=NULL;
    return OK;
}

Status DestroyLstack(LinkStack *S)//销毁一个栈
{
    if(S->top==NULL)
        return ERROR;
    S->top=NULL;
    free(S);
    return OK;
}

Status LPush(LinkStack *S,ElemType e)//元素入栈
{
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
    p->data=e;
    p->next=S->top;
    S->top=p;
    S->count++;
    return OK;
}

Status LPop(LinkStack *S,ElemType *e)//元素出栈
{
    LinkStackPtr q=(LinkStackPtr)malloc(sizeof(StackNode));
    if(LstackEmpty(LinkStack *S))
        return ERROR;
    *e=S->top->data;
    q=S->top;
    S->top=S->top->next;
    free(q);
    S->count--;
    return OK;
}

Status Lstacklength(LinkStack *S,int *length)//判断栈的长度
{
    if(S->top==NULL)
        return ERROR;
    *length=S->count-1;
    return OK;
}

Status GetTopLstack(LinkStack *S,ElemType *e)//得到栈顶元素
{
    if(S->top==-1)
        return ERROR;
    *e=S->top->data;
    return OK;
}
