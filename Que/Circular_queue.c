#include <stdio.h>

#define QUE_SIZE 4
int que[QUE_SIZE] = { 0, };
int head = 0;
int tail = 0;

int que_push(int data) {
	if ((tail + 1) % QUE_SIZE == head) {
		printf("que is full!!!\n");
		return -1;
	}
	que[tail] = data;
	tail = (++tail) % QUE_SIZE; // que tail inc

	return 0;
}

int que_pop() {
	int temp = 0;
	if (head == tail) {
		printf("que is empty!!!\n");
		return -1;
	}
	temp = que[head];
	que[head] = 0;
	head = (++head) % QUE_SIZE;

	return temp;
}

void que_print() {
	for (int i = 0; i < QUE_SIZE; i++) {
		printf("  [%d]:%d  ",i, que[i]);
	}
	printf("\n");
}

void main() {
	//push data~
	printf("== PUSH data ==\n");
	for (int i = 0; i < QUE_SIZE; i++) {
		que_push(i + 1);
		que_print();
	}
	//que is full!!!
	que_push(4);
	
	printf("\n\n");
	
	//pop data~
	printf("== POP data ==\n");
	for (int i = 0; i < QUE_SIZE; i++) {
		que_pop();
		que_print();
	}
	//que is empty~
	que_pop();
}
