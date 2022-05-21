#include <iostream>
using namespace std;

//typedef double element;

const int MAX_QUEUE_SIZE = 7;

template <typename element>  //element�� ������ Ÿ���̸�
class Queue {
public:
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

	Queue() {  //������
		front = 0;
		rear = 0;
	}

	bool is_empty_queue() {
		return (front == rear); //���Ұ� �����ϱ� ���� �� ����
	}

	bool is_queue_full() {
		return (front == (rear + 1) % MAX_QUEUE_SIZE);
	}

	void enQueue(element value) {
		if (is_queue_full()) {
			cout << "ERROR : QUEUE OVERFLOW" << endl;
			exit(1); 
		}
		else {
			//queue[++rear] = value;
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			queue[rear] = value;
		}
	}

	element deQueue() {
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE UNDERFLOW" << endl;
			exit(1);
		}
		else {
			//return queue[++front];
			front = (front + 1) % MAX_QUEUE_SIZE;
			return queue[front];
		}
	}

	int peek() { 
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE EMPTY" << endl;
		}
		else return queue[(front + 1) % MAX_QUEUE_SIZE];
	}

	void print_queue() {
		cout << "ť ����" << endl;
		if (front <= rear) {
			for (int i = front + 1; i <= rear; i++)
				cout << queue[i] << " ";
		}
		else { //front, rear ������ �ڹٲ� ���
			for (int i = front + 1; i <= rear + MAX_QUEUE_SIZE; i++)
				cout << queue[i % MAX_QUEUE_SIZE] << " ";
		}
		cout << endl;
	}
};

int main() {
	Queue<double> q;
	Queue<int> p; //���� Queue�� double, int �� ���� ���� �� ����

	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	q.enQueue(60);
	q.enQueue(70);
	q.deQueue();
	q.enQueue(80);
	q.enQueue(90); //n-1��ŭ�� ���� �� �ִ�.
	q.print_queue();
}