#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
	int item;
	struct list *next;
} Node;


Node *list_add(Node *head, int x)
{
        Node *tmp = NULL;

        tmp = (Node *)malloc(sizeof(Node));
        tmp->item = x;

        if (head == NULL) {
		tmp->next = NULL;
        }
	else
		tmp->next = head;

        head = tmp;
        return head;
}

Node *list_add_tail(Node *head, int x)
{
	Node *tmp = NULL;
	Node *ptr = NULL;

	tmp = (Node *)malloc(sizeof(Node));
	tmp->item = x;
	tmp->next = NULL;

	if (head == NULL) {
		tmp->next = NULL;
		head = tmp;
		return head;
	}
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		;
	}
	ptr->next = tmp;
	return head;
}

Node *reverse(Node *head)
{
	Node *curr, *prev, *tmp;

	curr = prev = tmp = NULL;
	curr = head;
	while (curr != NULL) {
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;

		//curr = ptr;
		//tmp = ptr->next;
		//curr->next = prev;
		//prev = curr;
		//ptr = tmp;
		//printf("curr: %d\n", curr->item);
	}
	head = prev;
	return head;
}

Node *add_lists(Node *l1, Node *l2)
{
	static Node *l3 = NULL;
	int num1, num2, num, digit, carry;

	carry = 0;
	while (l1 != NULL || l2 != NULL) {
		if (l1 == NULL)
			num1 = 0;
		else
			num1 = l1->item;

		if (l2 == NULL)
			num2 = 0;
		else
			num2 = l2->item;

		num = num1 + num2 + carry;
		digit = num % 10;
		carry = num / 10;
		l3 = list_add_tail(l3, digit);

		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
	}

	if (carry > 0)
		l3 = list_add_tail(l3, carry);

	return l3;
}

void display_list(Node *head)
{
	Node *ptr = NULL;

	for (ptr = head; ptr != NULL; ptr = ptr->next) {
		printf("%d->", ptr->item);
	}
	printf("\n");
}

int main()
{
	int i, n;
	char ch;
	char data[50];
	Node *l1 = NULL, *l2 = NULL, *l3 = NULL;

	memset(data, '\0', sizeof(data));
	scanf("%s", data);
	for (i = 0; data[i] != '\0'; i++) {
		ch = data[i];
		l1 = list_add(l1, ch-'0');
		l3 = list_add_tail(l3, ch-'0');
	}
	display_list(l1);
	//l1 = reverse(l1);
	display_list(l3);


	return 0;
}
