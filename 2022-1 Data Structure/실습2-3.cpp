#include <iostream>
using namespace std;

void main() {
	int scores[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int* ptr;

	ptr = scores; //����? ������ ����

	//ptr++; ��� ����
	//scores++; ��� �迭���̶�� å�Ӱ��� �־ �Ժη� �ٲ�� �ȵ�

	for (int i = 0; i < 10; i++) {
		cout << *(ptr + i) << endl;
		//cout << *(ptr++) << endl; �̰͵���
		cout << ptr[i] << endl; //�̷� ǥ������� ȥ���ؼ� ����! �ͼ��������� ����
		//ũ�� ���� 3���� ������ ǥ���ϴµ�
		cout << *(scores + i) << endl;
		cout << scores[i] << endl;
	}
}