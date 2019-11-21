#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
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

Status InitStack(*S);
Status DestroyStack(*S);
Status ClearStack(*S);
Status StackEmpty(S);
Status GetTop(S,*e);
Status Push(*S,e);
Status Pop(*S,*e);
Status StackLength(S);


#endif // STACK_H_INCLUDED
