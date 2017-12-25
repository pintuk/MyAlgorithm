// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} Node;


void inorder(Node *node)
{
	if (node == NULL) {
		return;
	}

	inorder(node->left);
	//printf("<%d> ", node->data);
	inorder(node->right);
}


Node * bst_insert(Node *node, int data)
{
	if (node == NULL) {
		node = (Node *)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	if (data <= node->data) {
		node->left = bst_insert(node->left, data);
	}
	else {
		node->right = bst_insert(node->right, data);
	}

	return node;
}

int bst_search(Node *node, int data)
{
	int found = 0;

	if (node == NULL) return 0;

	if (node->data == data) return 1;

	if (data < node->data)
		found = bst_search(node->left, data);
	else if (data > node->data)
		found = bst_search(node->right, data);

	return found;
}


int find_max(int A[], int N)
{
        int max = 0;
        int i;

        for (i = 0; i < N; i++) {
                if (A[i] >= 0 && A[i] > max)
                        max = A[i];
        }
        return max;
}

int solution(int A[], int N) 
{
    int max = 0;
    int i,j,k;
    Node * root = NULL;
    int found = 0;
    
    max = find_max(A, N);
    if (max <= 0) return 1;

    for (i = 0; i < N; i++) {
        if (A[i] <= 0) continue;

	found = bst_search(root, A[i]);
	if (found == 0)
		root = bst_insert(root, A[i]);
    }
    inorder(root);
    for (i = 1; i <= max; i++) {
	found = bst_search(root, i);
	if (found == 0) return i;
    }
    
    return max+1;   
}

int main()
{
	int A[1000000];
	int i,N;
	int Answer;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	Answer = solution(A, N);
	printf("Answer = %d\n", Answer);

	return 0;
}

