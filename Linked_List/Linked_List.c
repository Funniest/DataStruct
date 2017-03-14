#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *addr;
};

struct Node *first;

struct Node* push_node(struct Node *nodes, int data) {
	struct Node *temp, *newNode;

	newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->addr = NULL;

	nodes->addr = newNode;

	return newNode;
}

int pop_node(int data) {
	struct Node *del;
	struct Node *front, *back;

	del = first;
	
	//front node temp
	front = first;

	while (del->addr != NULL) {
		if (del->data == data) {
			back = del->addr;
			free(del);
			front->addr = back;
			break;
		}

		front = del;
		del = del->addr;
	}

	if (del->data == data) {
		back = del->addr;
		free(del);
		front->addr = back;
	}

	return -1;
}

void print_node(){
	struct Node *print;

	print = first->addr;

	if (print == NULL) {
		printf("Not Data!!\n");
		return;
	}

	while (print->addr != NULL) {
		printf("  %d  ", print->data);
		print = print->addr;
	}

	printf("  %d  ",print->data);
	printf("\n");
}

void main() {
	struct Node *nodes;

	first = (struct Node*)malloc(sizeof(struct Node));
	first->addr = NULL; // first node addr init

	nodes = first;

	nodes = push_node(nodes, 1);
	print_node();
	nodes = push_node(nodes, 2);
	print_node();
	nodes = push_node(nodes, 3);
	print_node();

	pop_node(2);
	print_node();
	pop_node(1);
	print_node();
	pop_node(3);

	free(first);
}
