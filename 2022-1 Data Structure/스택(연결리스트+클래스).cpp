#include <iostream>
using namespace std;

typedef int element;
class SNode {
public:
	element data;
	SNode* link;
};

SNode* Top = NULL;

class Stack {
public:
	SNode* Top;
	Stack() {  //������
		Top = NULL;
	}

	bool is_empty_stack() {
		return (Top == NULL);
	}

	void push(int value) {
		SNode* new_node = new SNode;
		new_node->data = value;
		//new_node->link = NULL;  �ٷ� ���� �ٿ� �ٲٴϱ� �ȳ־��

		//ù ����, ��ܿ� �߰�
		new_node->link = Top;
		Top = new_node;
	}

	int pop() {
		if (is_empty_stack()) {
			cout << "ERROR : STACK UNDERFLOW" << endl;
			exit(1);
		}
		else {
			element x = Top->data;
			Top = Top->link;
			return x;
		}
	}

	int peek() { //���� ���� �ִ� ���� ����?
		if (is_empty_stack()) {
			cout << "ERROR : STACK EMPTY" << endl;
		}
		else return Top->data;
	}

	void print_stack() {
		cout << "���� ����" << endl;
		for (SNode* list = Top; list != NULL;list=list->link) {
			cout << list->data << endl;
		}
	}
};


void main() {
	Stack s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	s.print_stack();
}