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

Status InitStack(*S)//��ʼ��һ��ջ
{
    S->top=NULL;
    S->count=0;
    return OK;
}

Status Push(*S,e)//����ջ��Ԫ��
{
    if(S->top=MAX-1)
        return ERROR;
    S->data[S->top]=e;
    S->top++;
    return OK;
}

int Pop(*S,*e)//���ջ��Ԫ��
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return *e;
}

int Prior(char s)//�÷���ֵ��ʾ�������ȼ�
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

Status GetTop(S,*e)//����ջ��Ԫ��
{
    if(S->top=-1)
        return ERROR;
    *e=S->data[S->top];
    return OK;
}

int main()
{
    //�����ֽ�ջ��
    //����ջ��Ԫ�أ�
    //Ȼ���÷��Ž�ջ��
    //�жϷ������ȼ��������������ַ��أ�����ֱ�ӱȽϷ�����ֵ�Ĵ�С�ж����ȼ���
    //���ȼ��ߵķ���ֱ����ջ��������ֱ����ջ�����ȼ��͵ģ��Ȱ���һ�����ŵ������������ֵ����������㣬�ٽ����ѹջ��
    //���������ţ�����Ӧ�����ŵĺ����Ԫ�ص�ջ�������㣬
    //���������Ԫ�صļ��㣬���������ջ��

}
