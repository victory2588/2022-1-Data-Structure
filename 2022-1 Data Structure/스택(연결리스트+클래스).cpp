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
	Stack() {  //생성자
		Top = NULL;
	}

	bool is_empty_stack() {
		return (Top == NULL);
	}

	void push(int value) {
		SNode* new_node = new SNode;
		new_node->data = value;
		//new_node->link = NULL;  바로 다음 줄에 바꾸니까 안넣어도됨

		//첫 노드로, 상단에 추가
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

	int peek() { //제일 위에 있는 값이 뭐야?
		if (is_empty_stack()) {
			cout << "ERROR : STACK EMPTY" << endl;
		}
		else return Top->data;
	}

	void print_stack() {
		cout << "스택 상태" << endl;
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