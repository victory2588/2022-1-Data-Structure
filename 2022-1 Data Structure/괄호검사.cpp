#include<iostream>
#include <stack>
using namespace std;

typedef char element;  //�ڷ����� �ٲ� �� �ִ� �͵��� �̷��� �����ϸ� ����
const int MAX_STACK_SIZE = 100;

class Stack {
public:
	element stack[MAX_STACK_SIZE];
	int top;

	Stack() {  //������
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
			exit(1); //return ���� ������. ���α׷� ��������
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

	int peek() { //���� ���� �ִ� ���� ����?
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
bool check_matching(char exp[])
{
	Stack s;
	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			s.push(exp[i]);
		else if (exp[i] == '}') {
			element ch = s.pop();
			if (ch != '}') return false;
			else continue; //¦�� ������ ��� ��
		}
		else if (exp[i] == ')') {
			element ch = s.pop();
			if (ch != ')') return false;
			else continue; //¦�� ������ ��� ��
		}
		else if (exp[i] == ']') {
			element ch = s.pop();
			if (ch != ']') return false;
			else continue; //¦�� ������ ��� ��
		}
		else continue;

	}
	if (s.is_empty_stack()) return true;
	else return false;

}


void main() {
	char expression[] = "(a+b*{c)^d}";
	if (check_matching(expression)) cout <<expression<< "��ȣ�˻� ����" << endl;
	else cout << expression << "��ȣ�˻� ����" << endl;
}