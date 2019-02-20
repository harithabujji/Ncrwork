#include<iostream>
using namespace std;

struct node
{
	int x;
	node* next;
};

void insertatend(node** head, int i)
{
	node* temp1 = NULL;
	node *temp = NULL;
	temp = new node();
	temp->x = i;
	temp->next = NULL;
	if (*head == NULL)
		*head = temp;
	else
	{
		temp1 = *head;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}

void display(node* head)
{
	node* temp = NULL;
	temp = head;
	if (temp == NULL)
		;
	else
	{
		cout << temp->x;
		display(temp->next);
	}
}
void insert_begin(node** head, int i)
{
	node* temp = NULL;
	temp = new node();
	temp->x = i;
	temp->next = NULL;
	if (*head == NULL)
		*head = temp;
	else
	{
		temp->next = *head;
		*head = temp;

	}

}
void insert_after(node** head, int i, int j)
{
	node* temp = NULL;
	node* temp1 = NULL;
	temp1 = *head;
	temp = new node();
	temp->x = j;
	temp->next = NULL;
	while (temp1->x != i)
		temp1 = temp1->next;
	if (temp1->next != NULL)
		temp->next = temp1->next;
	temp1->next = temp;

}
void delete_begin(node** head)
{
	node* temp = *head;
	*head = temp->next;
}

void delete_last(node** head)
{
	node* temp;
	node* temp1;
	temp = *head;
	temp1 = temp->next;
	while (temp1->next != NULL) {
		temp = temp->next;
		temp1 = temp1->next;
	}
	temp->next = NULL;
}

void delete_after(node** head, int i)
{
	node* temp = NULL;
	temp = *head;

	while (temp->x != i && temp->next != NULL)
		temp = temp->next;
	if (temp->next == NULL)
		cout << "not found";
	temp->next = temp->next->next;
}
int main()
{
	node* head = NULL;
	insertatend(&head, 1);
	insertatend(&head, 2);
	insertatend(&head, 3);
	insertatend(&head, 4);
	insertatend(&head, 5);
	display(head);
	cout << endl;
	delete_after(&head, 33);
	display(head);
	system("pause");
	return 0;


}