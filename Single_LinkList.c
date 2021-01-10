#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}Node, *ListNode;

ListNode create()
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = 0;
	newNode -> next = NULL;
	return newNode;
}

void printLL(ListNode node)
{
	if (node -> val > 0)
	{
		node = node -> next;
		while(node != NULL)
		{
			printf("%d\n", node -> val);
			node = node -> next;
		}
	}
	else
	{
		printf("List is empty\n");
	}
}

void addhead(ListNode node, int val)
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = val;
	if (node -> next == NULL)
	{
		newNode -> next = NULL;
		node -> next = newNode;
		node -> val++; 
	}
	else
	{
		newNode -> next = node -> next;
		node -> next = newNode;
		node -> val++; 
	}
}

void addtail(ListNode node, int val)
{
	ListNode newNode = malloc(sizeof(Node));
	newNode -> val = val;
	newNode -> next = NULL;
	if (node -> next == NULL)
	{
		node -> next = newNode;
		node -> val++; 
	}
	else
	{
		node -> val++;
		while(node -> next != NULL)
		{
			node = node -> next;
		}
		node -> next = newNode;
	}

}

void delhead(ListNode node)
{
	if (node -> next == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		ListNode pt = node -> next;
		node -> next = pt -> next;
		free(pt);
		pt = NULL;
		node -> val--;
	}
}

void deltail(ListNode node)
{
	if (node -> next == NULL)
	{
		 printf("List is empty\n");
	}
	else
	{
		node -> val--;
		while(node -> next -> next != NULL)
		{
			node = node -> next;
		}
		ListNode end = node -> next;
		free(end);
		end = NULL;
		node -> next = NULL;
	}
}

void freeALL(ListNode node)
{
	ListNode pt, after;
	if (node -> val > 0)
	{
		pt = node -> next;
		while(pt != NULL)
		{
			after = pt -> next;
			free(pt);
			pt = after;
			node -> val--;
		}
		node -> next = NULL;
	}
}

void reverse(ListNode node)
{
	if (node -> next -> next != NULL)
	{
		int count = node -> val;
		ListNode ptr = node -> next -> next;
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
	ListNode list = create();
	addhead(list, 10);
	addhead(list, 20);
	addhead(list, 30);
	addtail(list, 77);
	addtail(list, 78);

	deltail(list);
	delhead(list);

	printf("%d\n", list -> val);
	printLL(list);

	printf("\n");
	freeALL(list);

	printf("%d\n", list -> val);
	printLL(list);

	printf("\n");

	addhead(list, 17);
	addhead(list, -21);
	addhead(list, 19);
	addtail(list, -13);

	reverse(list);

	printf("%d\n", list -> val);
	printLL(list);

	quicksort(list -> next, NULL);

	printf("\n");
	printLL(list);
	
	return 0;
}
