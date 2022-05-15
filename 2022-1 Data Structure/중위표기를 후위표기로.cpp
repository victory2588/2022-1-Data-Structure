#include<iostream>
using namespace std;

typedef double element;  //�ڷ����� �ٲ� �� �ִ� �͵��� �̷��� �����ϸ� ����
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

	void push(element value) {
		if (is_full()) {
			cout << "ERROR : STACK OVERFLOW" << endl;
			exit(1); //return ���� ������. ���α׷� ��������
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

	element peek() { //���� ���� �ִ� ��
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

	char exp[100];
	char postfix[100];

	cout << "Enter infix expression : ";
	cin.getline(exp, 100);
	int j = 0;
	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			s.push(exp[i]);
		} //�����ڸ� push, �ݴ� ��ȣ�� pop, �ǿ����� �״�� ���, ���� ��ȣ ����
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

	//���� ǥ��� ��� : postfix�� �о� ������ ���
	for (int i = 0; i < strlen(postfix); i++) {

		if (postfix[i] == '+') {
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 + op2);
		}
		else if (postfix[i] == '-') { //�յ� ���� ����
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 - op2);
		}
		else if (postfix[i] == '*') {
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 * op2);
		}
		else if (postfix[i] == '/') { //�յ� ���� ����
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 / op2);
		}

		else { //�ǿ����ڸ�
			s.push(postfix[i] - '0'); //���� 0�� ���� �ƽ�Ű�ڵ� ���� ������ ���� �ذ�
		}
	}
	cout << exp << "=" << s.pop() << endl;
}