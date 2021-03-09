#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}Node, *ListNode;

ListNode *create()
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = 0;
	newNode -> next = NULL;

	static ListNode arr[2];

	arr[0] = newNode;
	arr[1] = NULL;

	return arr;
}

void printLL(ListNode *node)
{
	if (node[0] -> val > 0)
	{
		ListNode ptr = node[0] -> next;
		while(ptr != NULL)
		{
			printf("%d\n", ptr -> val);
			ptr = ptr -> next;
		}
	}
	else
	{
		printf("List is empty\n");
	}
}

void addhead(ListNode *node, int val)
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = val;
	if (node[0] -> next == NULL)
	{
		newNode -> next = NULL;
		node[0] -> next = newNode;
		node[1] = newNode;
		node[0] -> val++; 
	}
	else
	{
		newNode -> next = node[0] -> next;
		node[0] -> next = newNode;
		node[0] -> val++; 
	}
}

void addtail(ListNode *node, int val)
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = val;
	newNode -> next = NULL;
	if (node[0] -> next == NULL)
	{
		node[0] -> next = newNode;
		node[1] = newNode;
		node[0] -> val++; 
	}
	else
	{
		node[0] -> val++;
		node[1] -> next = newNode;
		node[1] = newNode;
	}
}

void delhead(ListNode *node)
{
	if (node[0] -> next == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		ListNode pt = node[0] -> next;
		node[0] -> next = pt -> next;
		free(pt);
		pt = NULL;
		node[0] -> val--;
	}
}

void deltail(ListNode *node)
{
	if (node[0] -> next == NULL)
	{
		 printf("List is empty\n");
	}
	else
	{
		node[0] -> val--;
		ListNode ptr = node[0] -> next;
		while(ptr -> next != node[1])
		{
			ptr = ptr -> next;
		}
		free(node[1]);
		node[1] = ptr;
		node[1] -> next = NULL;
	}
}

void freeALL(ListNode *node)
{
	ListNode pt, after;
	if (node[0] -> val > 0)
	{
		pt = node[0] -> next;
		while(pt != NULL)
		{
			after = pt -> next;
			free(pt);
			pt = after;
			node[0] -> val--;
		}
		node[0] -> next = NULL;
		node[1] = NULL;
	}
}

void reverse(ListNode *node)
{
	if (node[0] -> next -> next != NULL)
	{
		int count = node[0] -> val;
		ListNode ptr = node[0] -> next -> next;
		while(ptr != NULL)
		{
			addhead(node, ptr -> val);
			ptr = ptr -> next;
		}
		for (int i = 0; i < count - 1 ; ++i)
		{
			deltail(node);
		}
	}
}

void swap(ListNode a, ListNode b)
{
	int temp;
	temp = a -> val;
	(*a).val = (*b).val;
	(*b).val = temp;
}

void quicksort(ListNode start, ListNode end)
{
	if (start == NULL || start == end)
	{
		 return;
	}

	ListNode r = start -> next;
	ListNode l = start;
	while(r != end)
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
	ListNode *list = create();
	addhead(list, 10);
	addhead(list, 20);
	addhead(list, 30);
	addtail(list, 77);
	addtail(list, 78);

	deltail(list);
	delhead(list);

	printf("%d\n", list[0] -> val);
	printLL(list);

	printf("\n");
	freeALL(list);

	printf("%d\n", list[0] -> val);
	printLL(list);

	printf("\n");

	addhead(list, 17);
	addhead(list, -21);
	addhead(list, 19);
	addtail(list, -13);

	reverse(list);

	printf("%d\n", list[0] -> val);
	printLL(list);

	quicksort(list[0] -> next, NULL);

	printf("\n");
	printLL(list);
	
	return 0;
}
