#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

int main()
{
    printf("��ѡ��˳��ջ�Ļ���������\n");
    printf("1.���ջ�ĳ��Ȳ��Զ���ո�ջ��\n");
    printf("2.����һ��˳��ջ���Զ��ж�ջ����\n");
    printf("3.����ջԪ�ء�\n")
    printf("4.���ջ��Ԫ�ء�\n");
    printf("5.��ո�ջ��\n");
    printf("6.���ٸ�ջ��\n");
    int a;
    scanf("%d",&a);
    switch(a)
    {
      case'1':printf("��ջ�ĳ���Ϊ��",StackLength(S));ClearStack(*S);break;
      case'2':Push(*S,e);printf("˳��ջ�ѽ�������������Ƿ�ջ����%d(1:��,0:��)",StackEmpty(S));break;
      case'3':Pop(*S,*e);printf("���ڵ���ջ��Ԫ�أ�\n",*e);break;
      case'4':Pop(*S,*e);printf("���ڵ���ջ��Ԫ�أ�\n",*e);break;
      case'5':ClearStack(*S);printf("��ջ����ա�\n");break;
      case'6':DestroyStack(*S);printf("��ջ�����١�\n");break;
      default:printf("enter data error.\n");
    }
    return 0;
}
