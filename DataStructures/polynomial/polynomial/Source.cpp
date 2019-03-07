#include<iostream>
using namespace std;
struct Node
{
	int coef;
	int pow;
	Node* next;
};

//insert new node at last
void insertAtLast(struct Node** head_ref, int coef, int pow)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->coef = coef;
	new_node->pow = pow;
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
	while (node!= NULL)
	{
		printf("%dx^%d", node->coef, node->pow);
		node = node->next;
		if (node != NULL)
			printf(" + ");
	}
}
// Function Adding two polynomial numbers
void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly)
{
	while (poly1->next && poly2->next)
	{
		if (poly1->pow > poly2->pow)
		{
			poly->pow = poly1->pow;
			poly->coef = poly1->coef;
			poly1 = poly1->next;
		}
		else if (poly1->pow < poly2->pow)
		{
			poly->pow = poly2->pow;
			poly->coef = poly2->coef;
			poly2 = poly2->next;
		} 
		else
		{
			poly->pow = poly1->pow;
			poly->coef= poly1->coef + poly2->coef;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		poly->next = (struct Node *)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
	while (poly1->next || poly2->next)
	{
		if (poly1->next)
		{
			poly->pow = poly1->pow;
			poly->coef = poly1->coef;
			poly1 = poly1->next;
		}
		if (poly2->next)
		{
			poly->pow = poly2->pow;
			poly->coef = poly2->coef;
			poly2 = poly2->next;
		}
		poly->next = (struct Node *)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
	
}

int main()
{
	struct Node *poly1 = (struct Node*)malloc(sizeof(Node)); 
	struct Node *poly2 = (struct Node*)malloc(sizeof(Node));
	struct Node *poly=NULL;
	poly1 = NULL; poly2 = NULL; 
	poly = (struct Node *)malloc(sizeof(struct Node));
	int ch = 0;
	int coef,pow;
	while (1)
	{
		printf("\n 0: EXIT \n 1: Insert a new node in Polynomial 1 \n 2: Insert a new node in polynomial 2 \n 3: Display Polynomial 1 4 : Display Polynomial 2 \n 5: Addition of two polynomials \n Enter :");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n enter the coefficient : ");
			scanf_s("%d", &coef);
			printf("\n enter the power : ");
			scanf_s("%d", &pow);
			insertAtLast(&poly1,coef,pow);
			break;
		case 2:
			printf("\n enter the coefficient : ");
			scanf_s("%d", &coef);
			printf("\n enter the power : ");
			scanf_s("%d", &pow);
			insertAtLast(&poly2, coef, pow);
			break;
		case 3:
			printf("\n1st Polynomial: ");
			printList(poly1);
			break;
		case 4:
			printf("\n2nd Polynomial: ");
			printList(poly2);
			break;
		case 5:
			polyadd(poly1, poly2, poly);
				printf("\nAdded polynomial: ");
			printList(poly);
			break;
		case 0:
			return 0;
		default:
			printf("\n INVALID CHOICE\n");
		}
	}
	
	return 0;
}