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
		Head = new_node;
	}
	else{
		Node* list = Head;
		while (list->link != NULL) //마지막 원소가 아닌 경우
			list = list->link;
		list->link = new_node;
	}
}

void insert_node_at_front(Node* new_node) { //C
	new_node->link = Head;
	Head = new_node;
}

void insert_node(int value) {
	Node* new_node = new Node; //동적 메모리 할당
	new_node->data = value;
	new_node->link = NULL;

	insert_node_at_front(new_node);
	//insert_node_at_rear(new_node);
}

void delete_node(int value) {
	Node* list = Head;
	if (Head == NULL) {
		cout << "빈 리스트는 지울 수 없습니다." << endl;
	}
	else if (Head->data == value) {
		Head = Head->link;
		return;
	}
	else {
		while (list->link != NULL) {
			if (list->link->data == value) {
				list->link = list->link->link; //앞 방의 주소를 내가 가질게
				return;
			}
			else list = list->link; //찾는게 없으면 똑같이 나옴.. 찾는게 없을때 없다고 말해주면 좋을듯
		}
	}
}

void print_list() {
	cout << "연결 리스트 출력" << endl;
	for (Node* list = Head; list != NULL; list = list->link) {
		if (list->link == NULL) {
			cout << list->data << endl;
		}
		else cout << list->data << "->";
	}
	cout << endl;
}

void main() {
	cout << "몇 개의 숫자를 넣으시겠습니까?: ";
	cin >> num;
	for (int i = 0; i < num;i+=1) {
		cout << "삽입할 숫자를 적어주세요: ";
		cin >> value;
		insert_node(value);
		cout << endl;
		print_list();
	}
	cout << "삭제할 숫자를 입력해주세요: ";
	cin >> del;
	delete_node(del);
	cout << endl;
	print_list();
}