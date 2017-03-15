# Tree
### 트리의 특징
앞서 글을 쓴 스택, 큐, 리스트 등은 선형적 구조를 가지는 반면, 트리는 비 선형 구조를 가지고 있습니다.

아래 그림 같은 느낌으로 구성되어 있습니다.

![Alt text](https://github.com/Funniest/study/blob/master/DataStruct/Tree/img/Tree.PNG)

트리는 탐색 속도와 삽입, 삭제등이 빨라 여러 곳에서 쓰입니다.

트리  구조는  대게 리눅스, 윈도우 파일 구조를 보면 한번씩 볼 수 있습니다.

이번에 공부해 본 것은 이진 트리인데, 차수의 개수가 2개 이하인 트리를 말합니다.

주 특징은 노드를 최대 2개 가질 수 있고, 서브 트리 간의 순서가 존재 합니다.

n개의 노드를 가진 이진 트리는 n-1개의 간선을 가진다고 합니다.

2진 트리의 순회 방식은 크게 3가지가 있는데, 아래 그림 처럼 전위 순회, 후위 순회, 중위 순회가 있습니다.

![Alt text](https://github.com/Funniest/study/blob/master/DataStruct/Tree/img/Circuit.PNG)

탐색에는 주로 재귀 호출을 이용한다고 알려져 있습니다.

### 소스코드

```
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
```
