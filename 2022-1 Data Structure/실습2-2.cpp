#include <iostream>
using namespace std;

/*void main() {
	int scores[10];

	cout << scores << endl;
	cout << &scores << endl;
	cout << &scores[0] << endl;
	cout << &scores[1] << endl; //���� ������� 4�� ũ�� ����

} //�迭�� ������ �ּҰ� ����!*/

void main() {
	int scores[10] = { 10,20,30,40,50,60,70,80,90,100 };

	cout << scores << endl;
	cout << &scores << endl;
	cout << &scores[0] << endl;

	for (int i = 0; i < 10; i++) {
		//cout << *(scores+i) << endl; �̷� ���� ǥ���� �ͼ���������
		cout << scores[i] << endl; //��� �ۼ��ص� ��ǻ�ʹ� ��ó�� �� �ٲ�
	}
}