#include <iostream>
using namespace std;

class Node {
public: //public ���� ��
	int data;
	Node* llink;
	Node* rlink;
};

Node* Head = NULL; //��� �����͸� ���� ������ ����!

void insert_node(int value) {
	Node* new_node = new Node; //���� �޸� �Ҵ�

	new_node->data = value;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	//ù ���� �߰�
	/*new_node->llink = Head;
	new_node->rlink = Head->rlink;
	Head->rlink->llink = new_node;
	Head->rlink = new_node;*/

	//������ ���� �߰�
	new_node->rlink = Head;
	new_node->llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
}

void delete_node(int value) {
	for (Node* removed = Head->rlink; removed != Head; removed = removed->rlink) {  //������� ���� ã�� ����
		if (removed->data == value) {
			removed->llink->rlink = removed->rlink;
			removed->rlink->llink = removed->llink;
			return;  //�ϳ��� ����ų�, ������ ����ų� �� ���� ������(���� ���� ���� �� �������� �ְ�..���)
		}
	}
	cout << "�ش��ϴ� ��尡 �����ϴ�." << endl << endl;
}

//if(list !=NULL) ==> if(list)  > 0�̸� ����, 0 �̿ܿ��� ��� ��!!!! <


void print_list() {
	cout << "���߿��� ����Ʈ ���" << endl;
	if (Head == Head->rlink) //Head->llink�� ��
		cout << "�� ����Ʈ�Դϴ�." << endl;
	for (Node* list = Head->rlink; list != Head; list = list->rlink) {  //���� �ٲٸ� �Ųٷ� ����� �� ����
		if (list->rlink == Head) {
			cout << list->data << endl;
		}
		else cout << list->data << "->";
	}
	cout << endl;
}

void main() {
	//��� ��� ��������!!!!
	Head = new Node;
	Head->llink = Head->rlink = Head; //�ڱ� �ڽ��� ����Ű���� �ʱ�ȭ!! 

	//�־��� ������ ���Ḯ��Ʈ �����
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
	//�� ����� ���� �� ����Ʈ�� ����
}