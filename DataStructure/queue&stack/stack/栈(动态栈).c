# include <stdio.h>
# include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int data;				//数据域
	struct Node *pNext;		//指针域
}NODE, *PNODE;				//NODE相当于struct Node, PNODE相当于struct Node *
typedef struct Stack
{
	PNODE Top;				//top顶部
	PNODE Bottom;			//Bottom底部
}STACK, *PSTACK;			//STACK相当于struct Stack, PSTACK相当于struct Stack *

void init(PSTACK);				//初始化
void push_stack(PSTACK , int);	//入栈(压栈)
void traversal_output(PSTACK );	//遍历输出
int air(PSTACK );				//判断是否为空
int pop(PSTACK , int*);			//出栈
void empty(PSTACK );				//清空栈
int main(void)
{
	int val;		//数值
	char yes_no;	//选择
	STACK S;
	init(&S);		//初始化

	do
	{
	printf("请输入你要入栈的值: ");
	scanf("%d", &val);
	push_stack(&S,val);
	printf("是否继续输入(y/其它): ");
	scanf(" %c", &yes_no);
	}while('y' == yes_no);

	printf("是否遍历输出(y/其它): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		traversal_output(&S);
	}
	else
	{
		printf("已选择不遍历输出!\n");
	}
	printf("\n\n\n");

	printf("是否出栈(y/其它): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		do
		{
			if( pop(&S , &val) )
			{
				printf("出栈成功,出栈的值为%d\n", val);
			}
			else
			{
				printf("出栈失败!\n");
				break;
			}
			printf("是否继续出栈(y/其它): ");
			scanf(" %c", &yes_no);
		}while('y' == yes_no);
	}
	else
	{
		printf("已选择不出栈!\n");
	}

	printf("\n\n\n");

	printf("是否清空栈(y/其它): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		empty(&S);
	}
	else
	{
		printf("已选择不清空栈!\n");
	}

	
	printf("是否遍历输出(y/其它): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		traversal_output(&S);
	}
	else
	{
		printf("已选择不遍历输出!\n");
	}
	return 0;
}

/* 初始化 */
void init(PSTACK S)
{
	S->Top = (PNODE)malloc(sizeof(NODE));
	if(S->Top == NULL)
	{
		printf("分配内存失败!\n");
		exit(-1);
	}
	else
	{
		S->Top->pNext = NULL;		//S->Top的指针域指向NULL
		S->Bottom = S->Top;			//S->Top赋给S->Bottom相当于S->Bottom的指针域也指向NULL
	}
	return;
}

/* 入栈 */
void push_stack(PSTACK S, int val)
{
	PNODE New = (PNODE)malloc(sizeof(NODE));

	New->data = val;
	New->pNext = S->Top;
	S->Top = New;

	return;
}

/* 遍历输出 */
void traversal_output(PSTACK S)
{
	PNODE Temp, Now;
	Now = S->Top;
		while(Now != S->Bottom)
		{
			printf("%d ", Now->data);
			Temp = Now->pNext;
			Now = Temp;
		}
		printf("\n");
}

/* 判断是否为空 */
int air(PSTACK S)
{
	if(S->Top == S->Bottom)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/* 出栈 */
int pop(PSTACK S, int* val)
{
	PNODE Now;
	Now = S->Top;
	if(Now != S->Bottom)
	{
		S->Top = Now->pNext;
		*val = Now->data;
		free(Now);
		Now = NULL;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/* 清空栈 */
void empty(PSTACK S)
{
	PNODE Now, Temp;
	Now = S->Top;
	while(Now != S->Bottom )
	{
		Temp = Now->pNext;
		free(Now);
		Now = Temp;
	}
	S->Bottom = S->Top;
}