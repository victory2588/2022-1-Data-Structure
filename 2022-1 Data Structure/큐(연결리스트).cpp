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

	Queue() {  //생성자
		front = rear = NULL;
	}

	bool is_empty_queue() {
		return (front == NULL); //원소가 없으니까 같을 수 있음
	}


	void enQueue(element value) {
		//새로운 노드 할당, 세팅
		Node* new_node = new Node;
		new_node->data = value;
		new_node->link = NULL;
		//연결리스트 제일 뒤에 추가
		if (is_empty_queue()) {  //rear가 NULL일 때를 생각하자
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

	int peek() { //제일 위에 있는 값
		if (is_empty_queue()) {
			cout << "ERROR : QUEUE EMPTY" << endl;
			exit(1);
		}
		else return front->data;
	}

	void print_queue() {
		cout << "큐 상태" << endl;
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