#Linked List
###연결리스트의 특징
연결리스트의 특징은 리스트에 있는 데이터는 다음 정보의 데이터를 가지고있어

값의 탐색 및 삽입 삭제가 용이합니다.

배열과의 차이점은 배열은 한번 할당한 값을 그대로 사용하는데,

리스트는 계속 새로운 데이터를 추가 및 삭제할 수 있어 메모리 관리도 용이합니다.

리스트는 아래 그림처럼 하나의 블럭(노드)마다 다음 블럭(노드)의 주소를 가지고 있습니다.

![Alt text](https://github.com/Funniest/DataStruct/blob/master/Linked_List/img/Node.PNG)

단일 연결리스트를 구현할 때에는 Head를 기점으로 노드를 이어주는 소스를 작성하면다.

###소스코드
본 프로그램은 Visual studio 2015환경에서 작성되었습니다.

```
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
```
