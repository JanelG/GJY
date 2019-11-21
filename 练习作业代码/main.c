#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

int main()
{
    printf("请选择顺序栈的基本操作：\n");
    printf("1.输出栈的长度并自动清空该栈。\n");
    printf("2.建立一个顺序栈并自动判断栈满。\n");
    printf("3.弹出栈元素。\n")
    printf("4.输出栈顶元素。\n");
    printf("5.清空该栈。\n");
    printf("6.销毁该栈。\n");
    int a;
    scanf("%d",&a);
    switch(a)
    {
      case'1':printf("该栈的长度为：",StackLength(S));ClearStack(*S);break;
      case'2':Push(*S,e);printf("顺序栈已建立，现在输出是否栈满：%d(1:是,0:否)",StackEmpty(S));break;
      case'3':Pop(*S,*e);printf("现在弹出栈顶元素：\n",*e);break;
      case'4':Pop(*S,*e);printf("现在弹出栈顶元素：\n",*e);break;
      case'5':ClearStack(*S);printf("该栈已清空。\n");break;
      case'6':DestroyStack(*S);printf("该栈已销毁。\n");break;
      default:printf("enter data error.\n");
    }
    return 0;
}
