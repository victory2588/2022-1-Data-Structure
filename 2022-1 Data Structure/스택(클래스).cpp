#include<iostream>
using namespace std;

typedef int element;  //�ڷ����� �ٲ� �� �ִ� �͵��� �̷��� �����ϸ� ����
const int MAX_STACK_SIZE = 100;

class Stack {
public:
	element stack[MAX_STACK_SIZE];
	int top;

	Stack() {  //������
		top = -1;
	}

	bool is_empty_stack() {
		return (top == -1);
	}

	bool is_full() {
		if (top == MAX_STACK_SIZE - 1) return true;
		else return false;
	}

	void push(int value) {
		if (is_full()) {
			cout << "ERROR : STACK OVERFLOW" << endl;
			exit(1); 
		}
		else {
			stack[++top] = value;
		}
	}

	int pop() {
		if (is_empty_stack()) {
			cout << "ERROR : STACK UNDERFLOW" << endl;
			exit(1);
		}
		else {
			return stack[top--];
		}
	}

	int peek() { 
		if (is_empty_stack()) {
			cout << "ERROR : STACK EMPTY" << endl;
		}
		else return stack[top];
	}

	void print_stack() {
		cout << "���� ����" << endl;
		for (int i = top; i >= 0; i--) {
			cout << stack[i] << endl;
		}
	}
};



void main() {
	Stack s;

	s.push(10);
	s.push(20);
	s.pop();
	s.print_stack();
}