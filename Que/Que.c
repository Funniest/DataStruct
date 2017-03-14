#include <stdio.h>

#define QUE_SIZE 3
int que[QUE_SIZE] = { 0, };
int head = 0;
int tail = 0;

int que_push(int data) {
	if (tail == QUE_SIZE) {
		printf("que is full!!!\n");
		return -1;
	}
	que[tail] = data;
	tail++; // que tail inc

	return 0;
}

int que_pop() {
	int temp = 0;
	if (head == tail) {
		printf("que is empty!!!\n");
		return -1;
	}
	temp = que[head];
	
	for (int i = 0; i < tail; i++) {
		if ( i == (tail - 1)) {
			que[i] = 0;
			break;
		}
		que[i] = que[i + 1];
	}
	
	tail--;

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
