#include <iostream>
using namespace std;

class Node {
public: //public 지정 꼭
	int data;
	Node* llink;
	Node* rlink;
};

Node* Head = NULL; //헤드 포인터를 전역 변수로 만듦!

void insert_node(int value) {
	Node* new_node = new Node; //동적 메모리 할당

	new_node->data = value;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	//첫 노드로 추가
	/*new_node->llink = Head;
	new_node->rlink = Head->rlink;
	Head->rlink->llink = new_node;
	Head->rlink = new_node;*/

	//마지막 노드로 추가
	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
}

void delete_node(int value) {
	for (Node* removed = Head->rlink; removed != Head; removed = removed->rlink) {  //지우려는 값을 찾는 과정
		if (removed->data == value) {
			removed->llink->rlink = removed->rlink;
			removed->rlink->llink = removed->llink;
			return;  //하나만 지울거냐, 여러개 지울거냐 등등에 따라 결정됨(지울 값이 여러 개 있을수도 있고..등등)
		}
	}
	cout << "해당하는 노드가 없습니다." << endl << endl;
}

//if(list !=NULL) ==> if(list)  > 0이면 거짓, 0 이외에는 모두 참!!!! <


void print_list() {
	cout << "이중연결 리스트 출력" << endl;
	if (Head == Head->rlink) //Head->llink도 됨
		cout << "빈 리스트입니다." << endl;
	for (Node* list = Head->rlink; list != Head; list = list->rlink) {  //순서 바꾸면 거꾸로 출력할 수 있음
		if (list->rlink == Head) {
			cout << list->data << endl;
		}
		else cout << list->data << "->";
	}
	cout << endl;
}

void main() {
	//헤드 노드 만들어야함!!!!
	Head = new Node;
	Head->llink = Head->rlink = Head; //자기 자신을 가리키도록 초기화!! 

	//주어진 값으로 연결리스트 만들기
	for (int i = 1; i <= 8; i++) {
		insert_node(i * 10);
	}
	print_list();

	delete_node(80); print_list();
	delete_node(70); print_list();
	delete_node(60); print_list();
	delete_node(50); print_list();
	delete_node(45); print_list();
	delete_node(40); print_list();
	delete_node(30); print_list();
	delete_node(20); print_list();
	delete_node(10); print_list();
	//다 지우고 나면 빈 리스트가 나옴
}