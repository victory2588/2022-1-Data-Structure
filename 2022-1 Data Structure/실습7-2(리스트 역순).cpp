#include <iostream>
using namespace std;

class Node {
public: //public ���� ��
	int data;
	Node* link;
};

Node* Head = NULL; //��� �����͸� ���� ������ ����! �̷��� ���� ������ ����������........ ������ swap �Լ����� �ô� ���� ������
int value;
int num;
int del;

void insert_node_at_middle() { //A

}

void insert_node_at_rear(Node* new_node) { //B
	if (Head == NULL) { //��尡 NULL�� ���
		Head = new_node;
	}
	else {
		Node* list = Head;
		while (list->link != NULL) //������ ���Ұ� �ƴ� ���
			list = list->link;
		list->link = new_node;
	}
}

void insert_node_at_front(Node* new_node) { //C
	new_node->link = Head;
	Head = new_node;
}

void insert_node(int value) {
	Node* new_node = new Node; //���� �޸� �Ҵ�
	new_node->data = value;
	new_node->link = NULL;

	//insert_node_at_front(new_node);
	insert_node_at_rear(new_node);
}

void delete_node(int value) {
	Node* list = Head;
	if (Head == NULL) {
		cout << "�� ����Ʈ�� ���� �� �����ϴ�." << endl;
	}
	else if (Head->data == value) {
		Head = Head->link;
		return;
	}
	else {
		while (list->link != NULL) {
			if (list->link->data == value) {
				list->link = list->link->link; //�� ���� �ּҸ� ���� ������
				return;
			}
			else list = list->link; //ã�°� ������ �Ȱ��� ����.. ã�°� ������ ���ٰ� �����ָ� ������
		}
	}
}

void print_list() {
	cout << "���� ����Ʈ ���" << endl;
	for (Node* list = Head; list != NULL; list = list->link) {
		if (list->link == NULL) {
			cout << list->data << endl;
		}
		else cout << list->data << "->";
	}
	cout << endl;
}

void reverse_list() {
	Node* ptr;
	Node* p, *q, *r; //Node *p, *q, *r �̰� �´µ� ����� *�� ������ �ٿ�����...

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

	//���� ����
	reverse_list();
	print_list();
}