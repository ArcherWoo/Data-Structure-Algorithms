#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int var;
	struct node *next;

}Node;

Node *head = NULL;
Node *current = NULL;

void addhead(int var)
{
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode -> var = var;
	
	if (head == NULL)
	{
		newNode -> next = NULL;
		head = newNode;
		current = newNode;
	}
	else
	{
		newNode ->next = head;
		head = newNode;
	}
}

void addtail(int var)
{
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode -> var = var;
	newNode -> next = NULL;

	if (head == NULL)
	{
		head = newNode;
		current = newNode;
	}
	else
	{
		current -> next =  newNode;
		current = newNode;
	}
}

void printLL()
{
	Node *pt = head;
	while(pt != NULL){
		printf("%d\n", pt -> var);
		pt = pt -> next;
	}
}

void freeALL()
{
	Node *ptr, *before;
	if(head != NULL)
	{
		ptr = head;
		while(ptr != NULL)
		{
			before = ptr;
			ptr = ptr -> next;
			free(before);
			before = NULL;
		}
		free(ptr);
		ptr = NULL;
	}
	head = NULL;
	current = NULL;
}

Node* reverse()
{
	Node *pt, *before;
	if (head == NULL || head -> next == NULL)
	{
		return head;
	}
	else
	{
		pt = head -> next;
		head -> next = NULL;
		while(pt != NULL)
		{
			before = pt;
			pt = pt -> next;
			addhead(before->var);
		}
		return head;
	}

}

int main(int argc, char const *argv[])
{
	addhead(4);
	addhead(3);
	addtail(5);
	addtail(6);

	printLL();

	freeALL();

	printf("\n");
	addhead(4);
	addhead(3);
	addhead(2);
	addhead(1);
	printLL();

	printf("\n");
	reverse();
	printLL();
	return 0;
}