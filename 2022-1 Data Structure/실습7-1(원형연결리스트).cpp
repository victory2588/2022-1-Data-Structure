#include <iostream>
using namespace std;

class Node {
public: //public ���� ��
	int data;
	Node* link;
};

Node* Head = NULL; //��� �����͸� ���� ������ ����!
int value;
int num;
int del;

void insert_node_at_middle() { //A

}

void insert_node_at_rear(Node* new_node) { //B
	if (Head == NULL) { //��尡 NULL�� ���
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
		Head = new_node; //Head�� �׻� ������ ��带 ����Ŵ
	}
}

void insert_node(int value) {
	Node* new_node = new Node; //���� �޸� �Ҵ�
	new_node->data = value;
	new_node->link = NULL;

	insert_node_at_rear(new_node);
}

void delete_node(int value) {
	Node* list = Head;
	if (Head == NULL) {
		cout << "�� ����Ʈ�� ���� �� �����ϴ�." << endl;
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
				if (Head == removed) //���� ��尡 ������ ����?!
					Head = list;
				return;
			}
			list = list->link;
		} while (list != Head);
	}
}

void print_list() {  //�������Ḯ��Ʈ�� ����Ʈ �ϴ°� �������� �����, do-while �� �Ἥ ������ ���(Head)�� ���� ������
	if (Head == NULL) {
		cout << "�� ����Ʈ�Դϴ�." << endl;
		return;
	}
	else {
		Node* list = Head;
		do {
			cout << list->link->data << " ";  //link�� ���� NULL�� �� ����!, ������ ȭ��ǥ �� ������ �Ϸ��� ��� ����?
			list = list->link;
		} while (list != Head);
	}
}

void reverse_list() {
	Node* ptr;
	Node* p, * q, * r; //Node *p, *q, *r �̰� �´µ� ����� *�� ������ �ٿ�����...

	p = Head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	Head = q; //������ �ʵ��� ����
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