# include <stdio.h>
# include <stdlib.h>

#define N 50	//可以改变静态栈总的大小
#define TRUE 1	//真
#define FALSE 0	//假

typedef struct Stack
{
	int stack[N];	//栈总的大小
	int top;		//顶部
	int bottom;		//底部
	int len;		//栈大小
}STACK, *PSTACK;

void init(PSTACK );					//初始化
void push_stack(PSTACK, int );		//入栈(压栈)
void traversal_output(PSTACK );		//遍历输出
int pop(PSTACK , int* );			//出栈
int air(PSTACK );					//判断栈是否为空
void empty(PSTACK );				//清空栈

int main(void)
{
	int val;			//输入的数值
	char yes_no;		//选择

	STACK S ;			//申请类型变量	S
	init(&S);
	do
	{
		printf("请输入你要入栈的值: ");
		scanf("%d", &val);
		push_stack(&S, val);			//入栈
		printf("是否继续入栈(y/其它): ");
		scanf(" %c", &yes_no);
	}while( 'y'==yes_no );

	printf("\n\n\n");

	printf("是否遍历输出(y/其它): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		traversal_output(&S);  //遍历输出
	}
	else
	{
		printf("已选择不遍历输出!\n");
	}
	printf("\n\n");

	printf("是否出栈(y/其它): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		do
		{
			if( pop(&S, &val) )
			{
				printf("出栈成功,出栈的值是%d\n", val);
				printf("是否出栈(y/其它): ");
				scanf(" %c", &yes_no);
			}
			else
			{
				printf("出栈失败!\n");
				break;
			}

		}while('y'==yes_no);
	}
	else
	{
		printf("已选择不出栈!\n");
	}

	printf("\n\n\n");

	printf("是否遍历输出(y/其它): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		traversal_output(&S);  //遍历输出
	}
	else
	{
		printf("已选择不遍历输出!\n");
	}

	printf("\n\n");

	printf("是否清空栈(y/其它): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		empty(&S);  //清空栈
	}
	else
	{
		printf("已选择不清空栈!\n");
	}

	printf("\n\n");

	printf("是否遍历输出(y/其它): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		traversal_output(&S);  //遍历输出
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
	S->top = S->bottom = -1;
	S->len = 0;
	return;
}

/* 入栈 */
void push_stack(PSTACK S, int val)
{
	if(S->len == N)
	{
		printf("入栈失败,栈已满");
	}
	else
	{
		S->top++;
		S->stack[S->top] = val;
		S->len++;
	}
	return;
}

/* 遍历输出 */
void traversal_output(PSTACK S)
{
	int temp = S->top;
	while( temp != S->bottom )
	{
		printf("%d ", S->stack[temp]);
		temp--;
	}
	return;
}

/* 出栈 */
int pop(PSTACK S, int* val)
{
	if( air(S) )
	{
		*val = S->stack[S->top]; 
		S->top--;
		S->len--;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/* 判断栈是否为空 */
int air(PSTACK S)
{
	if(S->top != S->bottom)
	{
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
	while(S->top != S->bottom)
	{
		S->stack[S->top] = NULL;
		S->top--;
	}
	S->len = 0;
	S->top = S->bottom;
	return;
}