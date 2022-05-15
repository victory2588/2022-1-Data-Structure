#include<iostream>
using namespace std;

typedef double element;  //자료형이 바뀔 수 있는 것들은 이렇게 선언하면 편함
const int MAX_STACK_SIZE = 100;

class Stack {
public:
	element stack[MAX_STACK_SIZE];
	int top;

	Stack() {  //생성자
		top = -1;
	}

	bool is_empty_stack() {
		return (top == -1);
	}

	bool is_full() {
		if (top == MAX_STACK_SIZE - 1) return true;
		else return false;
	}

	void push(element value) {
		if (is_full()) {
			cout << "ERROR : STACK OVERFLOW" << endl;
			exit(1); //return 보다 강력함. 프로그램 끝내버림
		}
		else {
			stack[++top] = value;
		}
	}

	element pop() {
		if (is_empty_stack()) {
			cout << "ERROR : STACK UNDERFLOW" << endl;
			exit(1);
		}
		else {
			return stack[top--];
		}
	}

	element peek() { //제일 위에 있는 값
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


void main() {
	Stack s;

	char exp[100];
	char postfix[100];

	cout << "Enter infix expression : ";
	cin.getline(exp, 100);
	int j = 0;
	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			s.push(exp[i]);
		} //연산자면 push, 닫는 괄호면 pop, 피연산자 그대로 출력, 여는 괄호 무시
		else if (exp[i] == ')') {
			postfix[j++] = s.pop();
		}
		else if (exp[i] == '(') {
			continue;
		}
		else postfix[j++] = exp[i];
	}
	postfix[j] = NULL;

	cout << postfix << endl;

	//후위 표기식 계산 : postfix를 읽어 수식을 계산
	for (int i = 0; i < strlen(postfix); i++) {

		if (postfix[i] == '+') {
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 + op2);
		}
		else if (postfix[i] == '-') { //앞뒤 순서 주의
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 - op2);
		}
		else if (postfix[i] == '*') {
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 * op2);
		}
		else if (postfix[i] == '/') { //앞뒤 순서 주의
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 / op2);
		}

		else { //피연산자면
			s.push(postfix[i] - '0'); //문자 0을 빼면 아스키코드 값이 나오는 문제 해결
		}
	}
	cout << exp << "=" << s.pop() << endl;
}