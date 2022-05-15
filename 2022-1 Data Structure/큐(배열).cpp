#include <iostream>
using namespace std;

typedef double element;

const int MAX_QUEUE_SIZE = 100;

class Queue {
public:
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

	Queue() {  //������
		front = -1;
		rear = -1;
	}

	bool is_empty_queue() {
		return (front == rear); //���Ұ� �����ϱ� ���� �� ����
	}

	bool is_queue_full() {
		if (rear == MAX_QUEUE_SIZE - 1) return true;
		else return false;
	}

	void enQueue(element value) {
		if (is_queue_full()) {
			cout << "ERROR : QUEUE OVERFLOW" << endl;
			exit(1); //return ���� ������. ���α׷� ��������
		}
		else {
			queue[++rear] = value;
		}
	}

	element deQueue() {
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE UNDERFLOW" << endl;
			exit(1);
		}
		else {
			return queue[++front];
		}
	}

	int peek() { //���� ���� �ִ� ���� ����?
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE EMPTY" << endl;
		}
		else return queue[front+1];
	}

	void print_queue() {
		cout << "ť ����" << endl;
		for (int i = front+1; i <= rear; i++) {
			cout << queue[i] << endl;
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