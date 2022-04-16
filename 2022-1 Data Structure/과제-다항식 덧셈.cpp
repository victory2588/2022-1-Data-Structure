#include <iostream>
using namespace std;

class Node {
public:
	int coef;
	int expo;
	Node* link;
};

class Head {
public:
	Node* head;
};

Head* createList(void) {
	Head* L;
	L = (Head*)malloc(sizeof(Head));
	L->head = NULL;
	return L;
}

void insert_node_at_rear(Head* L, int coef, int expo) {
	Node* newNode;
	Node* p;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	else {
		p = L->head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = newNode;
	}
}

void add(Head* A, Head* B, Head* C) {
	Node* pA = A->head;
	Node* pB = B->head;
	int sum;

	while (pA && pB) {
		if (pA->expo == pB->expo) {
			sum = pA->coef + pB->coef;
			insert_node_at_rear(C, sum, pA->expo);
			pA = pA->link; pB = pB->link;
		}
		else if (pA->expo > pB->expo) {
			insert_node_at_rear(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		else {
			insert_node_at_rear(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}
	for (; pA != NULL; pA = pA->link)
		insert_node_at_rear(C, pA->coef, pA->expo);
	for (; pB != NULL; pB = pB->link)
		insert_node_at_rear(C, pB->coef, pB->expo);
}

void print_list(Head* ex) {
	Node* p = ex->head;
	for (; p != NULL; p = p->link) {
		if (p->link == NULL) {
			cout << p->coef << "x^" << p->expo;
		}
		else cout << p->coef << "x^" << p->expo << " + ";
	}
	cout << endl;
}

int main(void) {
	Head* A, * B, * C;

	A = createList();
	B = createList();
	C = createList();

	insert_node_at_rear(A, 3, 12);
	insert_node_at_rear(A, 2, 8);
	insert_node_at_rear(A, 1, 0);
	printf("A =");
	print_list(A);
	cout << endl;

	insert_node_at_rear(B, 8, 12);
	insert_node_at_rear(B, -3, 10);
	insert_node_at_rear(B, 10, 6);
	printf("B =");
	print_list(B);
	cout << endl;

	add(A, B, C);
	printf("C =");
	print_list(C);
}