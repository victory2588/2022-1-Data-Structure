#include <iostream>
using namespace std;

typedef double element;

const int MAX_QUEUE_SIZE = 100;

class Queue {
public:
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

	Queue() {  //생성자
		front = -1;
		rear = -1;
	}

	bool is_empty_queue() {
		return (front == rear); //원소가 없으니까 같을 수 있음
	}

	bool is_queue_full() {
		if (rear == MAX_QUEUE_SIZE - 1) return true;
		else return false;
	}

	void enQueue(element value) {
		if (is_queue_full()) {
			cout << "ERROR : QUEUE OVERFLOW" << endl;
			exit(1); //return 보다 강력함. 프로그램 끝내버림
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

	int peek() { //제일 위에 있는 값이 뭐야?
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE EMPTY" << endl;
		}
		else return queue[front+1];
	}

	void print_queue() {
		cout << "큐 상태" << endl;
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