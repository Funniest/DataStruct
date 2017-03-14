#Que
###큐의 특징
스택은 마지막이 들어온 것이 먼저나오는 LIFO(Last Input First Out)방식인데,

큐는 그 반대로 먼저들어온 것이 먼저 나오는 FIFO(First in First Out)방식입니다.

예를 들자면 1,2,3을 넣으면 아래 그림처럼 하나씩 들어오고,

![Alt text](https://github.com/Funniest/DataStruct/blob/master/Que/img/PUSH.png)

나중에 빼낼 때에는 1,2,3순으로 출력됩니다.

![Alt text](https://github.com/Funniest/DataStruct/blob/master/Que/img/POP.png)

###소스 코드
본 프로그램은 Visual studio 2015환경에서 작성되었습니다.
```
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
```

##Circular queue
###원형 큐의 특징
위의 큐는 Que에서 데이터를 꺼낼 때마다 데이터의 이동이 일어나서 비효율적입니다.

그래서 큐의 끝과 처음을 이은 원형 큐라는 것이 생기게 되었는데,

데이터가 순환하며 저장되서 위의 큐 처럼 불필요한 이동이 일어나지 않습니다.

예를 들어1,2,3을 넣어 보겠습니다.

아래 그림처럼 원 형태로 데이터가 들어가는 것을 볼 수 있습니다.

(그리고 나니 뭔가 크롬 모양같내요;;)

PUSH

![Alt text](https://github.com/Funniest/DataStruct/blob/master/Que/img/Circular_PUSH.PNG)

POP

![Alt text](https://github.com/Funniest/DataStruct/blob/master/Que/img/Circular_POP.PNG)

*일반큐와 약간 다르게 % 연산자를 이용해서 구현을 하면됩니다.*

```
원형큐는 마지막 하나를 비워줘야 하는 것 같은 듯한 느낌이;;

다른 분들껏도 보았는데, 왠지 하나가 비는것 같내요 ㅋㅋ
```

###소스코드
본 프로그램은 Visual studio 2015환경에서 작성되었습니다.
```
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
```
