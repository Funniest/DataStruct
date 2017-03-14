#Stack
###스택의 특징
스택의 특징은 삽입을 하면 아래 차곡차곡 쌓이다가

나중에 빼낼 때 가장 나중에 입력한 값을 먼저 출력하는 LIFO(Last Input First Out)방식 입니다.

예를 들자면 1,2,3을 넣으면 아래 그림처럼 하나씩 쌓이고,

![Alt text](https://github.com/Funniest/study/blob/master/DataStruct/Stack/img/PUSH.png)

나중에 빼낼 때에는 3,2,1순으로 출력이 됩니다.

![Alt text](https://github.com/Funniest/study/blob/master/DataStruct/Stack/img/POP.png)

###소스코드

본 프로그램은 Visual studio 2015환경에서 작성되었습니다.

```

#include <stdio.h>

__stdcall call_printf(int data){

	char *format = "Pop data : %d";
	
	__asm{

		PUSH data

		PUSH format

		CALL printf

		POP EAX

		POP EAX

	}

}

void main() {

	//data push in stack

	__asm{

		PUSH 1		

		PUSH 2

		PUSH 3

	}

	//pop data

	__asm{

		POP EAX

		PUSH EAX

		CALL call_printf

		POP EAX

		PUSH EAX

		CALL call_printf

		POP EAX

		PUSH EAX

		CALL call_printf

	}

}

```
