#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int item;
	struct list *next;
} Node;

Node *push(Node *head, int digit, int k)
{
	int i = 1;
	Node *ptr, *tmp;

	if (head == NULL && k > 1)
		return NULL;

	printf("digit: %d, k = %d\n", digit, k);

	if (head == NULL && k == 1) {
		head = (Node *)malloc(sizeof(Node));
		head->item = digit;
		head->next = NULL;
		return head;
	}

	if (head != NULL && k == 1) {
		tmp = (Node *)malloc(sizeof(Node));
		tmp->item = digit;
		tmp->next = head;
		head = tmp;
		return head;
	}

	i = 1;
	for (ptr = head; ptr != NULL; ptr = ptr->next) {
		if (i == k-1) {
			tmp = (Node *)malloc(sizeof(Node));
			tmp->item = digit;
			tmp->next = ptr->next;
			ptr->next = tmp;
			return head;
		}
		i++;
	}

	return head;
}

Node *pop(Node *head, int k)
{
	int i = 1;
	Node *ptr, *tmp;

	if (head == NULL) return NULL;
	if (k <= 0) return head;

	if (k == 1) {
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
		return head;
	}

	i = 1;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		if (i == k-1) {
			tmp = ptr->next;
			ptr->next = tmp->next;
			free(tmp);
			return head;
		}
		i++;
	}
	return head;
}

void display(Node *head)
{
	Node *ptr;

	printf("display:\n");
	for (ptr = head; ptr != NULL; ptr = ptr->next) {
		printf("%d", ptr->item);
	}
	printf("\n");
}

int main()
{
	int i = 0;
	int M;
	char ch;
	char A[100];
	int op, digit, k;
	Node *head = NULL;

	while ((ch = getchar()) != '\n' && ch != EOF) {
                A[i++] = ch;
		head = push(head, ch-'0', i);
        }
	A[i] = '\0';
	//printf("str: %s\n", A);
	display(head);
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &op);
		if (op == 0) {
			scanf("%d %d", &digit, &k);
			head = push(head, digit, k);
			display(head);
		} else {
			scanf("%d", &k);
			head = pop(head, k);
			display(head);
		}
	}

	display(head);

	return 0;
}
