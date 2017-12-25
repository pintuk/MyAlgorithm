#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct LinkList {
	int item;
	struct LinkList * next;
} Node;


Node * insert(Node * head, int data)
{
	Node * tmp = NULL;

	//printf("%d -> \n", data);
	if (head == NULL) {
		head = (Node *) malloc(sizeof(Node));
		head->item = data;
		head->next = NULL;
		return head;
	}

	tmp = (Node *)malloc(sizeof(Node));
	tmp->item = data;
	tmp->next = head;
	head = tmp;

	return head;
}

Node * insert_end(Node * head, int data)
{
	Node * tmp; 
	Node * ptr;

	if (head == NULL) {
		head = insert(head, data);
		return head;
	}

	ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	tmp = (Node *)malloc(sizeof(Node));
	tmp->item = data;
	ptr->next = tmp;
	tmp->next = NULL;

	return head;
}

void display(Node *head)
{
	Node *ptr;

	for (ptr = head; ptr != NULL; ptr = ptr->next) {
		printf("->%d", ptr->item);
	}
	printf("->NULL");
	printf("\n");
}

Node * delete(Node *head)
{
	Node * tmp = NULL;

	if (head == NULL)
		return NULL;

	tmp = head;
	head = head->next;
	free(tmp);

	return head;
}

void delete_given(Node *given)
{
	Node *tmp;

	if (given == NULL || given->next == NULL)
		return;

	tmp = given->next;
	given->item = tmp->item;
	given->next = tmp->next;

	free(tmp);
}

int detect_loop(Node *head)
{
	Node *slow, *fast;

	slow = fast = head;
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return 1;
		}
	}

	return 0;
}

int find_middle(Node *head)
{
	Node * slow, * fast;

	slow = fast = head;
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return (slow->item);
}

void remove_duplicate(Node *head)
{
	Node *ptr1, *ptr2, *tmp;

	for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
		ptr2 = ptr1;
		printf("ptr1 item: %d\n", ptr1->item);
		while (ptr2->next != NULL) {
			if (ptr1->item == ptr2->next->item) {
				printf("ptr2 item: %d\n", ptr2->item);
				tmp = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(tmp);
			} else {
				ptr2 = ptr2->next;
			}
		}
	}
}

Node * kth_to_lastnode(Node *start, int k)
{
	Node *p1, *p2;
	int i;

	p1 = p2 = start;
	for (i = 0; i < k; i++) {
		if (p1 == NULL) return NULL;
		p1 = p1->next;
	}
	while (p1 != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p2;
}

int main()
{
	Node *head = NULL;
	int found = 0;
	int middle = 0;
	Node *knode = NULL;
	int kval = 0;

	head = insert(head, 10);
	head = insert(head, 20);
	head = insert(head, 30);
	head = insert(head, 10);
	head = insert(head, 10);
	head = insert(head, 20);
	head = insert(head, 60);
	head = insert(head, 10);
	head = insert(head, 30);
	head = insert(head, 20);
	head = insert(head, 50);
	head = insert(head, 60);
	head = insert(head, 70);
	head = insert(head, 80);
	head = insert(head, 90);
	head = insert(head, 70);
	head = insert(head, 60);

	printf("The link list is:\n");
	display(head);
#if 0
	//head->next->next->next->next = head->next->next;

	found = detect_loop(head);
	if (found == 1) {
		printf("Loop detected....exiting\n");
		return 0;
	}

	display(head);
	head = delete(head);
	printf("After delete =>\n");
	display(head);

	insert_end(head, 60);
	printf("After insert =>\n");
	display(head);

	printf("After delete given : %d\n", (head->next->next->next->item));
	delete_given(head->next->next->next);
	display(head);
#endif

	middle = find_middle(head);
	printf("Middle element = %d\n", middle);

	remove_duplicate(head);
	printf("After remove duplicates: \n");
	display(head);

	knode = kth_to_lastnode(head, 5);
	if (knode == NULL)
		kval = 0;
	else
		kval = knode->item;
	printf("kth to last node item = %d\n", kval);
	
	return 0;
}
