#include <iostream>
using namespace std;

typedef double element;

class Node {
public:
	element data;
	Node* link;
};

class Queue {
public:
	Node* front, * rear;

	Queue() {  //������
		front = rear = NULL;
	}

	bool is_empty_queue() {
		return (front == NULL); //���Ұ� �����ϱ� ���� �� ����
	}


	void enQueue(element value) {
		//���ο� ��� �Ҵ�, ����
		Node* new_node = new Node;
		new_node->data = value;
		new_node->link = NULL;
		//���Ḯ��Ʈ ���� �ڿ� �߰�
		if (is_empty_queue()) {  //rear�� NULL�� ���� ��������
			front = rear = new_node;
		}
		else {
			rear->link = new_node;
			rear = new_node;
		}
	}

	element deQueue() {
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE UNDERFLOW" << endl;
			exit(1);
		}
		else {
			element x = front->data;
			front = front->link;
			if (front == NULL) rear = NULL;
			return x;
		}
	}

	int peek() { //���� ���� �ִ� ��
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE EMPTY" << endl;
			exit(1);
		}
		else return front->data;
	}

	void print_queue() {
		cout << "ť ����" << endl;
		for (Node* list = front; list != NULL; list = list->link) {
			cout << list->data << " ";
		}
	}
};

int main() {
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	q.print_queue();
}