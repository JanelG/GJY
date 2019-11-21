#ifndef LSTACK_H_INCLUDED
#define LSTACK_H_INCLUDED
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

Status initLstack(LinkStack *S);
Status LstackEmpty(LinkStack *S);
Status ClearLstack(LinkStack *S);
Status DestroyLstack(LinkStack *S);
Status LPush(LinkStack *S,ElemType e);
Status LPop(LinkStack *S,ElemType *e);
Status Lstacklength(LinkStack *S,int *length);
Status GetTopLstack(LinkStack *S,ElemType *e);

#endif // LSTACK_H_INCLUDED
