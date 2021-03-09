#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//1.函数调用 2.中断 3.表达式 4.中断求值 5.内存分配 6.缓冲处理 7.迷宫

typedef struct Node
{
  int data;
  struct Node *Next;
}Node, *PNODE; // Node等价于struct Node，PNODE等价于struct Node *
   
typedef struct Stack
{
  PNODE pTop;
  PNODE pBottom;
}STACK, *PSTACK; // PSATCK等价于struck Stack

//pTop和pBottom都指向一个头指针，即为创建成功
void init(PSTACK ps)//造出空栈 ps保存S的地址
{
  ps->pTop=(PNODE)malloc(sizeof(NODE));//把头指针的地址给ptop，ptop此时指向头指针
  
  if (NULL==ps->pTop)
  {
    exit(-1);
  }
  else
  {
    ps->pBottom=ps->pTop;//把pTop的地址给到bottom，则两个都指向了头指针
    //ptop里存放了之前分配内存的地址，把这个地址赋给了pbottom，则pbottom也就指向了它
    ps->pTop->pNext=NULL;//清空指针域
  }
}

// init函数完成了ptop和pbottom都指向了一个空栈
void push(PSTACK ps,int val)
{
  PNODE pNew=(PNODE)malloc(sizeof(NODE));//造一个新结点
  pNew->data=val;
    
  //下一步我们要让new结点指向下一个空栈，思路是把ptop的值赋给new，因为top里面存放的是空栈的地址
  pNew->pNext=ps->pTop;//虽然ptop和pbottom里都存放着前面空栈的地址
  
  //但只能选top，因为压栈是从头部往下压的，把top里存放的地址给new，那么new就指向了下一个空栈
  ps->pTop=pNew;//ptop指向了新的结点
}
   
void traverse(PSTACK ps)//遍历输出
{
  PNODE p=ps->pTop;//p永远指向栈顶
  while (p!=ps->bottom)
  {
    printf("%d",p->data);
    p=p->pNext;
  }
  printf(" ");
}
   
bool empty(PSTACK ps)
{
  if(ps->pTop==ps->pBottom)
    return ture;
  else
    return false;
}
   
//把ps所指向的栈出栈一次，并把出栈的元素存入pval形参所指向的变量中
bool pop(PSTACK ps,int *pVal)
{
  if (empt(PSTACK ps))//ps本身存放的就是S的地址
  {
    return false;
  }
  else
  {
    //这儿不能直接来一个pTop=pTop->pNext;内存没有释放
    PNODE r=ps->pTop;
    
    //旁边新加一个r，我们要让r指向栈顶，因为ptop本来是指向栈顶的
    //我们让r指向ptop所指的栈顶，即把ptop所指的指针赋给r，不就是r指向了栈顶嘛
    //把ptop指向的东西给r，r也就指向了这个东西
    *pVal=r->data;
    
    //赋值
     ps->pTop=r->pNext;
    
    //r的next指针也就是栈顶的右半边，右半边本来是指向栈顶下边的，
    //我们把r的next的指针（右半边）给ptop，那么ptop不就指向下边了
    free(r);
    r=NULL;//防止内存在后面使用r，释放
  }
  return true;
}
   
void clear(pSTACK ps)//清空元素
{
  if(empty(ps))
  {
    return;
  }
  else
  {
    PNODE p=ps->pTop;
   
    while(p!=ps->bottom)
    {
      ps->pTop=p->pNext;
      free(p);
    }
  }
}
   
int main(void)
{
  STACK S;
   
  init(&S);
  push(&S,1);
  push(&S,2);
  pop(&S,&val);
  printf("%d",val);
  traverse(&S);
  clear(&S);

}