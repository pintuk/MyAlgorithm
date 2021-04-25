#include <stdio.h>

struct stack {
	int x;
	char c;
};

int Stack[1001];
int top = -1;

void push(struct stack *s)
{
	if (s->x != -1)
		s->c = 0;
	else
		s->x = -1;
	Stack[top++] = s;
}

struct stack *pop()
{
	struct stack *s = NULL;
	if (isempty())
		return NULL;
	s = Stack[top--];

	return s;
}

int checkop(char op)
{
	if (op == '(' || op == ')' || op == '[' || op == ']')
		return 1;

	return 0;
}

int solve(char *infix)
{
	int i;
	sturct stack s = {-1,0};

	top = 0;
	for (i=0; infix[i] != '\0'; i++) {
		char op = infix[i];
		if (checkop(op)) {
			if (op == ')') {
				int value = 0;

				do {
					s = pop();
					if (s == NULL)
						break;
					if (s.c == 0)
						value += s.x;
				} while (s.c != '(');
			}
		}
	}
}

int main()
{
	int i;
	int infix[1001];

	scanf("%s", infix);

	Answer = solve(infix);

	printf("Answer = %d\n", Answer);

	return 0;
}
