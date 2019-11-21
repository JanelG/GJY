#include <stdio.h>
#include <stdlib.h>
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

Status Push(*S,e)//输入栈的元素
{
    if(S->top=MAX-1)
        return ERROR;
    S->data[S->top]=e;
    S->top++;
    return OK;
}

int Pop(*S,*e)//输出栈的元素
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return *e;
}

int Prior(char s)//用返回值表示符号优先级
{
    switch(s)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

Status GetTop(S,*e)//弹出栈顶元素
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    return OK;
}

int main()
{
    //让数字进栈，
    //弹出栈顶元素，
    //然后让符号进栈，
    //判断符号优先级，将符号用数字返回，可以直接比较返回数值的大小判断优先级，
    //优先级高的符号直接入栈，左括号直接入栈。优先级低的，先把上一个符号弹出，并将数字弹出进行运算，再将结果压栈。
    //遇到右括号，将对应左括号的后面的元素弹栈进行运算，
    //最后进行最后元素的计算，将结果弹出栈。

}
