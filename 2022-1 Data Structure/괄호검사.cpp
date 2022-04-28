#include<iostream>
#include <stack>
using namespace std;

typedef char element;  //자료형이 바뀔 수 있는 것들은 이렇게 선언하면 편함
const int MAX_STACK_SIZE = 100;

class Stack {
public:
	element stack[MAX_STACK_SIZE];
	int top;

	Stack() {  //생성자
		top = -1;
	}

	bool is_empty_stack() {
		//if (top == -1) return true;
		//else return false;
		return (top == -1);
	}

	bool is_full() {
		if (top == MAX_STACK_SIZE - 1) return true;
		else return false;
	}

	void push(int value) {
		if (is_full()) {
			cout << "ERROR : STACK OVERFLOW" << endl;
			exit(1); //return 보다 강력함. 프로그램 끝내버림
		}
		else {
			//top++;
			//stack[top] = value;
			stack[++top] = value;
		}
	}

	int pop() {
		if (is_empty_stack()) {
			cout << "ERROR : STACK UNDERFLOW" << endl;
			exit(1);
		}
		else {
			//int x = stack[top];
			//top--;
			//return x;
			return stack[top--];
		}
	}

	int peek() { //제일 위에 있는 값이 뭐야?
		if (is_empty_stack()) {
			cout << "ERROR : STACK EMPTY" << endl;
		}
		else return stack[top];
	}

	void print_stack() {
		cout << "스택 상태" << endl;
		for (int i = top; i >= 0; i--) {
			cout << stack[i] << endl;
		}
	}
};
bool check_matching(char exp[])
{
	Stack s;
	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			s.push(exp[i]);
		else if (exp[i] == '}') {
			element ch = s.pop();
			if (ch != '}') return false;
			else continue; //짝이 맞으면 계속 함
		}
		else if (exp[i] == ')') {
			element ch = s.pop();
			if (ch != ')') return false;
			else continue; //짝이 맞으면 계속 함
		}
		else if (exp[i] == ']') {
			element ch = s.pop();
			if (ch != ']') return false;
			else continue; //짝이 맞으면 계속 함
		}
		else continue;

	}
	if (s.is_empty_stack()) return true;
	else return false;

}


void main() {
	char expression[] = "(a+b*{c)^d}";
	if (check_matching(expression)) cout <<expression<< "괄호검사 성공" << endl;
	else cout << expression << "괄호검사 실패" << endl;
}