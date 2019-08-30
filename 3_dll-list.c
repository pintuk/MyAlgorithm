#include <stdio.h>
#include <stdlib.h>


typedef struct list {
	int item;
	struct list *next;
	struct list *prev;
} Node;


Node *list_add_head(Node *head, int item)
{
	Node *ptr = NULL;
	Node *tmp = NULL;

	tmp = (Node *)malloc(sizeof(Node));
	tmp->item = item;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (head == NULL) {
		tmp->next = NULL;
		tmp->prev = NULL;
	} else {
		tmp->next = head;
		tmp->prev = NULL;
		head->prev = tmp;
	}
	head = tmp;
	return head;
}

Node *list_add_tail(Node *head, int item)
{
	Node *ptr = NULL, *tmp = NULL;

	tmp = (Node *)malloc(sizeof(Node));
	tmp->item = item;

	if (head == NULL) {
		tmp->next = NULL;
		tmp->prev = NULL;
		head = tmp;
		return head;
	}

	ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = tmp;
	tmp->next = NULL;
	tmp->prev = ptr;

	return head;
}

Node *get_tail(Node *head)
{
	Node *ptr = NULL;

	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		;
	}
	return ptr;
}

void remove_node(Node *given)
{
	Node *tmp1 = NULL, *tmp2 = NULL;

	if (given == NULL) return;
	if (given->next == NULL && given->prev == NULL) {
		free(given);
		given = NULL;
		return;
	}
	printf("remove_node: reached here1\n");

	tmp1 = given->prev;
	if (given->next == NULL) {
		tmp1->next = NULL;
	} else {
		tmp2 = given->next;
		if (given->prev != NULL)
			tmp1->next = given->next;
		tmp2->prev = given->prev;
	}
	free(given);
	given = NULL;
}

void display_list(Node *head)
{
	Node *ptr = NULL;

	if (head == NULL) return;

	for (ptr = head; ptr != NULL; ptr = ptr->next) {
		printf("%d->", ptr->item);
	}
	printf("\n");
}

void display_reverse(Node *head)
{
        Node *ptr = NULL, *back = NULL;

	if (head == NULL) return;

	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;

        for (back = ptr; back != NULL; back = back->prev) {
                printf("%d->", back->item);
        }
        printf("\n");
}

int main()
{
	int i, N, val;
	Node *head = NULL;
	Node *tail = NULL;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &val);
		//head = list_add_head(head, val);
		head = list_add_tail(head, val);
	}
	display_list(head);
	tail = get_tail(head);
	printf("tail node: %d\n", tail->item);
	val = tail->item;
	if (tail == head) {
		printf("tail equal to head\n");
		remove_node(head);
		head = NULL;
	}
	else {
		remove_node(tail);
		tail = NULL;
	}
	printf("After remove last node:\n");
	display_list(head);
	head = list_add_head(head, val);
	printf("After add <%d> in front::\n", val);
	display_list(head);
	printf("After reverse:\n");
	display_reverse(head);

	return 0;
}
