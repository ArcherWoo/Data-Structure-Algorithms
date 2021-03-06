#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}Node, *ListNode;

ListNode head = NULL;
ListNode current = NULL;

void printLL()
{
	ListNode pt = head;
	while(pt != NULL)
	{
		printf("%d\n", pt -> val);
		pt = pt -> next;
	}
}

void addhead(int val)
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = val;

	if (head == NULL)
	{
		newNode -> next = NULL;
		head = newNode;
		current = newNode;
	}
	else
	{
		newNode -> next = head;
		head = newNode;
	}
}

void addtail(int val)
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = val;
	newNode -> next = NULL;

	if (head == NULL)
	{
		head = newNode;
		current = newNode;
	}
	else
	{
		current -> next = newNode;
		current = newNode;
	}
}

void delhead()
{
	if (head == current)
	{
		free(head);
		head = NULL;
		current = NULL;
	}
	else
	{
		ListNode pt = head -> next;
		free(head);
		head = pt;
	}
}

void deltail()
{
	if (head == current)
	{
		free(head);
		head = NULL;
		current = NULL;
	}
	else
	{
		ListNode pt = head;
		while(pt -> next != current)
		{
			pt = pt -> next;
		}
		free(current);
		pt -> next = NULL;
		current = pt;
	}
}

void freeALL()
{
	if (head != NULL)
	{
		ListNode pt, after;
		pt = head;
		while(pt != NULL)
		{
			after = pt -> next;
			free(pt);
			pt = after;
		}
		head = NULL;
		current = NULL;
	}
}

void reverse()
{
	if (head != current)
	{
		ListNode pt = head -> next, ptr = head;
		while(pt != NULL)
		{
			addhead(pt -> val);
			pt = pt -> next;
		}
		while(current != ptr)
		{
			deltail();
		}
	}
}

void swap(ListNode a, ListNode b)
{
	int temp = a -> val;
	a -> val = b -> val;
	b -> val = temp;
}

void quicksort(ListNode start, ListNode end)
{
	if (start == NULL || start == end)
	{
		return;
	}
	ListNode r = start -> next;
	ListNode l = start;
	while(r != NULL)
	{
		if (r -> val < start -> val)
		{
			l = l -> next;
			swap(l, r);
		}
		r = r -> next;
	}
	swap(l, start);	
	quicksort(start, l);
	quicksort(l -> next, end);
}

int main(int argc, char const *argv[])
{
	addhead(3);
	addhead(2);
	addhead(1);
	addtail(4);
	addtail(5);

	printLL();

	delhead();
	deltail();

	printf("\n");

	printLL();

	freeALL();

	addtail(77);
	addtail(88);
	addtail(99);

	reverse();

	printf("\n");

	printLL();

	addhead(100);

	quicksort(head, NULL);

	printf("\n");
	printLL();

	return 0;
}
