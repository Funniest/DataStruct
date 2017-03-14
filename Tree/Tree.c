#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *L_node, *R_node;
}tree_node;

tree_node* create_node(int data) {
	tree_node *node = (tree_node*)malloc(sizeof(tree_node));

	if (!node) {
		return NULL;
	}

	node->data = data;
	node->L_node = node->R_node = NULL;

	return node;
}

int push_node(tree_node** node, int data) {
	tree_node *temp = *node;

	if (*node == NULL) {
		if (!(*node = create_node(data))) {
			return -1;
		}
		return 0;
	}

	while (1) {
		int cmp_data = temp->data - data;
		
		if (cmp_data == 0) {
			return -1;
		}

		if (cmp_data < 0) {
			if (temp->L_node != NULL) {
				temp = temp->L_node;
			}
			else {
				temp->L_node = create_node(data);
				return 0;
			}
		}

		else {
			if (temp->R_node != NULL) {
				temp = temp->R_node;
			}
			else {
				temp->R_node = create_node(data);
				return 0;
			}
		}
	}

	return 0;
}

void preorder(tree_node** node) {
	if (*node != NULL) {
		printf("  %d  ", (*node)->data);
		preorder(&((*node)->L_node));
		preorder(&((*node)->R_node));
	}
}

void inorder(tree_node** node) {
	if (*node != NULL) {
		inorder((*node)->L_node);
		printf("  %d  ", (*node)->data);
		inorder((*node)->R_node);
	}
}

void postorder(tree_node** node){
	if (*node != NULL) {
		postorder(&((*node)->L_node));
		postorder(&((*node)->R_node));
		printf("  %d  ", (*node)->data);
	}
}

void del_tree(tree_node** node) {
	release_tree(node);
	*node = 0;
}

int release_tree(tree_node** node) {
	if (*node != NULL) {
		release_tree(&((*node)->L_node));
		release_tree(&((*node)->R_node));
		free(*node);
	}

	return 0;
}
void main() {
	tree_node* Root = NULL;
	
	push_node(&Root, 1);
	preorder(&Root);
	printf("\n");
	push_node(&Root, 2);
	preorder(&Root);
	printf("\n");
	push_node(&Root, 3);
	preorder(&Root);
	printf("\n");

	del_tree(&Root);

	preorder(&Root);
}
