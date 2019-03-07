#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};
//Insert data at first
void insertatfirst(Node** head_ref, int new_data)
{
	struct Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	new_node->prev = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	(*head_ref)->prev = new_node;
	*head_ref = new_node;
}
//insert at last
void insertatLast(Node** head_ref, int new_data)
{
	struct Node *new_node = (Node*)malloc(sizeof(Node));
	struct Node *last = (Node*)malloc(sizeof(Node)); 
	last = *head_ref;
	new_node->data = new_data;
	new_node->prev = *head_ref;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
	return;
}
//inserts before 
void insertbefore(Node** head_ref, int prev_data, int new_data)
{
	struct Node *new_node = (Node*)malloc(sizeof(Node));
	struct Node *last = (Node*)malloc(sizeof(Node));
	last = *head_ref;
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while (last != NULL && last->data != prev_data)
	{
		last = last->next;
	}
	new_node->prev = last->prev;
	new_node->next = last;
	last->prev->next = new_node;
	last->prev = new_node;
}
//inserts after
void insertafter(Node** head_ref, int prev_data, int new_data)
{
	struct Node *new_node = (Node*)malloc(sizeof(Node));
	struct Node *last = (Node*)malloc(sizeof(Node));
	last = *head_ref;
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while (last != NULL && last->data != prev_data)
	{
		last = last->next;
	}
	new_node->next = last->next;
	new_node->prev = last;
	new_node->next->prev = new_node;
	last->next = new_node;
}
//Printing linked list
void display(struct Node *node)
{
	struct Node *last = NULL;
	printf("\nTraversal in forward direction \n");
	while (node != NULL)
	{
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
	printf("\nTraversal in reverse direction \n");
	while (last != NULL)
	{
		printf(" %d ", last->data);
		last = last->prev;
	}
	printf("\n");
}
void reverse(struct Node **head_ref)
{
	struct Node *temp = NULL;
	struct Node *current = *head_ref;
	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
		*head_ref = temp->prev;
}
int main()
{
	struct Node *head = (Node*)malloc(sizeof(Node));
	head = NULL;
	int ch = 0, x, y;
	while (1)
	{
		printf("\n 0:EXIT \n 1:Insert at First \n 2:Insert at Last \n 3.Insert before given node \n 4:Insert after given node \n 5:Display \n 6:reverse \n Enter :");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n Enter data to insert :");
			scanf_s("%d", &x);
			insertatfirst(&head, x);
			break;
		case 2:
			printf("\n Enter data to insert :");
			scanf_s("%d", &x);
			insertatLast(&head, x);
			break;
		case 3:
			printf("\n Enter before which data needs to insert :");
			scanf_s("%d", &x);
			printf("\n Enter data to insert : ");
			scanf_s("%d", &y);
			insertbefore(&head, x, y);
			break;
		case 4:
			printf("\n Enter after which data needs to insert :");
			scanf_s("%d", &x);
			printf("\n Enter data to insert :");
			scanf_s("%d", &y);
			insertafter(&head, x, y);
			break;
		case 5:
			display(head);
			break;
		case 6:
			reverse(&head);
			display(head);
			break;
		case 0:
			return 0;
		default:
			printf("\n INVALID CHOICE\n");
		}
	}
}