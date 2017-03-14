#include <stdio.h>

__stdcall call_printf(int data) {
	char *format = "Pop data : %d\n";
	__asm {
		PUSH data
		PUSH format
		CALL printf
		POP EAX
		POP EAX
	}
}

void main() {
	//data push in stack
	__asm {
		PUSH 1
		PUSH 2
		PUSH 3
	}
	//pop data
	__asm {
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