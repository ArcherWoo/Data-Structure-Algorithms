# include <stdio.h>
# include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int data;				//������
	struct Node *pNext;		//ָ����
}NODE, *PNODE;				//NODE�൱��struct Node, PNODE�൱��struct Node *
typedef struct Stack
{
	PNODE Top;				//top����
	PNODE Bottom;			//Bottom�ײ�
}STACK, *PSTACK;			//STACK�൱��struct Stack, PSTACK�൱��struct Stack *

void init(PSTACK);				//��ʼ��
void push_stack(PSTACK , int);	//��ջ(ѹջ)
void traversal_output(PSTACK );	//�������
int air(PSTACK );				//�ж��Ƿ�Ϊ��
int pop(PSTACK , int*);			//��ջ
void empty(PSTACK );				//���ջ
int main(void)
{
	int val;		//��ֵ
	char yes_no;	//ѡ��
	STACK S;
	init(&S);		//��ʼ��

	do
	{
	printf("��������Ҫ��ջ��ֵ: ");
	scanf("%d", &val);
	push_stack(&S,val);
	printf("�Ƿ��������(y/����): ");
	scanf(" %c", &yes_no);
	}while('y' == yes_no);

	printf("�Ƿ�������(y/����): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		traversal_output(&S);
	}
	else
	{
		printf("��ѡ�񲻱������!\n");
	}
	printf("\n\n\n");

	printf("�Ƿ��ջ(y/����): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		do
		{
			if( pop(&S , &val) )
			{
				printf("��ջ�ɹ�,��ջ��ֵΪ%d\n", val);
			}
			else
			{
				printf("��ջʧ��!\n");
				break;
			}
			printf("�Ƿ������ջ(y/����): ");
			scanf(" %c", &yes_no);
		}while('y' == yes_no);
	}
	else
	{
		printf("��ѡ�񲻳�ջ!\n");
	}

	printf("\n\n\n");

	printf("�Ƿ����ջ(y/����): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		empty(&S);
	}
	else
	{
		printf("��ѡ�����ջ!\n");
	}

	
	printf("�Ƿ�������(y/����): ");
	scanf(" %c", &yes_no);
	if('y' == yes_no)
	{
		traversal_output(&S);
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
	S->Top = (PNODE)malloc(sizeof(NODE));
	if(S->Top == NULL)
	{
		printf("�����ڴ�ʧ��!\n");
		exit(-1);
	}
	else
	{
		S->Top->pNext = NULL;		//S->Top��ָ����ָ��NULL
		S->Bottom = S->Top;			//S->Top����S->Bottom�൱��S->Bottom��ָ����Ҳָ��NULL
	}
	return;
}

/* ��ջ */
void push_stack(PSTACK S, int val)
{
	PNODE New = (PNODE)malloc(sizeof(NODE));

	New->data = val;
	New->pNext = S->Top;
	S->Top = New;

	return;
}

/* ������� */
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

/* �ж��Ƿ�Ϊ�� */
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

/* ��ջ */
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

/* ���ջ */
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