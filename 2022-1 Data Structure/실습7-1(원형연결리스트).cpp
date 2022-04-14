#include <iostream>
using namespace std;

class Node {
public: //public 지정 꼭
	int data;
	Node* link;
};

Node* Head = NULL; //헤드 포인터를 전역 변수로 만듦!
int value;
int num;
int del;

void insert_node_at_middle() { //A

}

void insert_node_at_rear(Node* new_node) { //B
	if (Head == NULL) { //헤드가 NULL일 경우
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
		Head = new_node; //Head는 항상 마지막 노드를 가리킴
	}
}

void insert_node(int value) {
	Node* new_node = new Node; //동적 메모리 할당
	new_node->data = value;
	new_node->link = NULL;

	insert_node_at_rear(new_node);
}

void delete_node(int value) {
	Node* list = Head;
	if (Head == NULL) {
		cout << "빈 리스트는 지울 수 없습니다." << endl;
		return;
	}
	else if (Head->link == Head && Head->data == value) {
		Head = NULL;
	}
	else {
		Node* list = Head;
		do {
			if (list->link->data == value) {
				Node* removed = list->link;
				list->link = removed->link; // list->link=list->link->link;
				if (Head == removed) //지울 노드가 마지막 노드면?!
					Head = list;
				return;
			}
			list = list->link;
		} while (list != Head);
	}
}

void print_list() {  //원형연결리스트를 프린트 하는게 생각보다 어려움, do-while 문 써서 마지막 노드(Head)와 같을 때까지
	if (Head == NULL) {
		cout << "빈 리스트입니다." << endl;
		return;
	}
	else {
		Node* list = Head;
		do {
			cout << list->link->data << " ";  //link는 절대 NULL일 수 없다!, 마지막 화살표 안 나오게 하려면 어떻게 하지?
			list = list->link;
		} while (list != Head);
	}
}

void reverse_list() {
	Node* ptr;
	Node* p, * q, * r; //Node *p, *q, *r 이게 맞는데 맘대로 *를 앞으로 붙여버림...

	p = Head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	Head = q; //빼먹지 않도록 조심
}

void main() {
	insert_node(10);
	insert_node(20);
	insert_node(30);
	insert_node(40);
	insert_node(50);
	insert_node(60);
	print_list();

	cout << endl;

	delete_node(10);
	delete_node(25);
	delete_node(60);
	print_list();
}