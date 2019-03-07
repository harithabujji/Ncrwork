#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
//insert data at first
void insertatfirst(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
// To insert a element after a given node
int insertAfter(struct Node** head_ref, int new_data,int prev_data)
{
	if (*head_ref == NULL)
	{
		printf("the given previous node cannot be NULL");
		return -1;
	}
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp = *head_ref;
	while (temp != NULL)
	{
		if (temp->data == prev_data)
		{
			struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
			new_node->data = new_data;
			new_node->next = temp->next;
			temp->next = new_node;
			return 1;
		}
		temp= temp->next;
	}
	return -1;
}
//insert new node at last
void insertAtLast(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_ref; 
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
//Printing linked list
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}
//Deleting node at first
void deleteatfirst(struct Node **head_ref)
{
	if (*head_ref== NULL)
		return;
	struct Node *n1 = (struct Node*)malloc(sizeof(Node));
	n1 = (*head_ref)->next;
	(*head_ref) = n1;

}
//Delete node at last
void deleteatlast(struct Node **head_ref)
{
	struct Node *temp = (struct Node*)malloc(sizeof(Node));
	struct Node *m = (struct Node*)malloc(sizeof(Node));
	temp = (*head_ref);
	if (temp == NULL)
		return;
	while (temp->next != NULL)
	{
		m = temp;
		temp = temp->next;
	}
	m->next = NULL;
	free(temp);
}
//Main
int main()
{
	Node* head =(struct Node*)malloc(sizeof(Node));
	head = NULL;
	int data,temp;
	int ch = 0, c = 0;
	printf("\n For first linked list");
	while (1)
	{
		printf("\n 0: EXIT \n 1: Insert a new node at first \n 2: Insert a new node after given node\n 3: Insert new node at last \n 4: Display Linked List \n 5: Delete at first \n 6: Delete at last \n Enter :");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n enter data to insert at first : ");
			scanf_s("%d", &data);
			insertatfirst(&head, data);
			break;
		case 2:
			printf("\n enter the prev data to insert after :");
			scanf_s("%d", &temp);
			printf("\n enter data to insert : ");
			scanf_s("%d", &data);
			if ((insertAfter(&head, data, temp)) == -1)
			{
				printf("\n The Prev node was not found \n");
			}
			break;
		case 3:
			printf("\n enter data to insert at last : ");
			scanf_s("%d", &data);
			insertAtLast(&head, data);
			break;
		case 4:
			printList(head);
		    break;
		case 5:
			deleteatfirst(&head);
			break;
		case 6:
			deleteatlast(&head);
			break;
		case 0:
			return 0;
		default:
			printf("\n Choice is invalid");
		}
	}
	system("pause");
	return 0;
}