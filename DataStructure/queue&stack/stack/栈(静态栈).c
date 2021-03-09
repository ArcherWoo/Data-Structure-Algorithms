# include <stdio.h>
# include <stdlib.h>

#define N 50	//���Ըı侲̬ջ�ܵĴ�С
#define TRUE 1	//��
#define FALSE 0	//��

typedef struct Stack
{
	int stack[N];	//ջ�ܵĴ�С
	int top;		//����
	int bottom;		//�ײ�
	int len;		//ջ��С
}STACK, *PSTACK;

void init(PSTACK );					//��ʼ��
void push_stack(PSTACK, int );		//��ջ(ѹջ)
void traversal_output(PSTACK );		//�������
int pop(PSTACK , int* );			//��ջ
int air(PSTACK );					//�ж�ջ�Ƿ�Ϊ��
void empty(PSTACK );				//���ջ

int main(void)
{
	int val;			//�������ֵ
	char yes_no;		//ѡ��

	STACK S ;			//�������ͱ���	S
	init(&S);
	do
	{
		printf("��������Ҫ��ջ��ֵ: ");
		scanf("%d", &val);
		push_stack(&S, val);			//��ջ
		printf("�Ƿ������ջ(y/����): ");
		scanf(" %c", &yes_no);
	}while( 'y'==yes_no );

	printf("\n\n\n");

	printf("�Ƿ�������(y/����): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		traversal_output(&S);  //�������
	}
	else
	{
		printf("��ѡ�񲻱������!\n");
	}
	printf("\n\n");

	printf("�Ƿ��ջ(y/����): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		do
		{
			if( pop(&S, &val) )
			{
				printf("��ջ�ɹ�,��ջ��ֵ��%d\n", val);
				printf("�Ƿ��ջ(y/����): ");
				scanf(" %c", &yes_no);
			}
			else
			{
				printf("��ջʧ��!\n");
				break;
			}

		}while('y'==yes_no);
	}
	else
	{
		printf("��ѡ�񲻳�ջ!\n");
	}

	printf("\n\n\n");

	printf("�Ƿ�������(y/����): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		traversal_output(&S);  //�������
	}
	else
	{
		printf("��ѡ�񲻱������!\n");
	}

	printf("\n\n");

	printf("�Ƿ����ջ(y/����): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		empty(&S);  //���ջ
	}
	else
	{
		printf("��ѡ�����ջ!\n");
	}

	printf("\n\n");

	printf("�Ƿ�������(y/����): ");
	scanf(" %c", &yes_no);
	if('y'==yes_no)
	{
		traversal_output(&S);  //�������
	}
	else
	{
		printf("��ѡ�񲻱������!\n");
	}
	return 0;
}

/* ��ʼ�� */
void init(PSTACK S)
{
	S->top = S->bottom = -1;
	S->len = 0;
	return;
}

/* ��ջ */
void push_stack(PSTACK S, int val)
{
	if(S->len == N)
	{
		printf("��ջʧ��,ջ����");
	}
	else
	{
		S->top++;
		S->stack[S->top] = val;
		S->len++;
	}
	return;
}

/* ������� */
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

/* ��ջ */
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

/* �ж�ջ�Ƿ�Ϊ�� */
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
/* ���ջ */

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