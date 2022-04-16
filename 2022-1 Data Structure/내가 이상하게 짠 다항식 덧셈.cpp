#include <iostream>
using namespace std;

class Node {
public:
	int coef;
	int exponent;
	Node* link;
};

Node* A = NULL;
Node* B = NULL;
Node* C = NULL;

void insert_node_at_rearA(Node* new_node) {
	if (A == NULL) { //헤드가 NULL일 경우
		A = new_node;
	}
	else {
		Node* list = A;
		while (list->link != NULL) //마지막 원소가 아닌 경우
			list = list->link;
		list->link = new_node;
	}
}

void insert_node_at_rearB(Node* new_node) {
	if (B == NULL) { //헤드가 NULL일 경우
		B = new_node;
	}
	else {
		Node* list = B;
		while (list->link != NULL) //마지막 원소가 아닌 경우
			list = list->link;
		list->link = new_node;
	}
}
void insert_node_at_rearC(Node* new_node) {
	if (C == NULL) { //헤드가 NULL일 경우
		C = new_node;
	}
	else {
		Node* list = C;
		while (list->link != NULL) //마지막 원소가 아닌 경우
			list = list->link;
		list->link = new_node;
	}
}

void insert_nodeA(int value1, int value2) {
	Node* new_nodeA = new Node;

	new_nodeA->coef = value1;
	new_nodeA->exponent = value2;
	new_nodeA->link = NULL;

	insert_node_at_rearA(new_nodeA);
}

void insert_nodeB(int value1, int value2) {
	Node* new_nodeB = new Node;

	new_nodeB->coef = value1;
	new_nodeB->exponent = value2;
	new_nodeB->link = NULL;

	insert_node_at_rearB(new_nodeB);
}

void insert_nodeC(int value1, int value2) {
	Node* new_nodeC = new Node;

	new_nodeC->coef = value1;
	new_nodeC->exponent = value2;
	new_nodeC->link = NULL;

	insert_node_at_rearC(new_nodeC);
}

void aPb(Node* A, Node* B) {
	Node* p = A;
	Node* q = B;
	while (A && B) {
		if (p->exponent == q->exponent) {
			insert_nodeC(p->coef + q->coef, p->exponent);
			p = p->link;
			q = q->link;
		}
		else if (p->exponent > q->exponent) {
			insert_nodeC(p->coef, p->exponent);
			p = p->link;
		}
		else {
			insert_nodeC(q->coef, q->exponent);
			q = q->link;
		}
	}
	for (; A != NULL; A = A->link) insert_nodeC(A->coef, A->exponent);
	for (; B != NULL; B = B->link) insert_nodeC(B->coef, B->exponent);
}

void print_list(Node* ex) {
	for (Node* list = ex; list != NULL; list = list->link) {
		if (list->link == NULL) {
			cout << list->coef << "x^" << list->exponent;
		}
		else cout << list->coef << "x^" << list->exponent << "+";
	}
	cout << endl;
}

void main() {
	insert_nodeA(3, 12);
	insert_nodeA(2, 8);
	insert_nodeA(1, 0);
	printf("A = ");
	print_list(A);

	insert_nodeB(8, 12);
	insert_nodeB(3, 10);
	insert_nodeB(10, 6);
	printf("B = ");
	print_list(B);

	aPb(A, B);

	printf("C = ");
	print_list(C);
}