#include <iostream>
using namespace std;

void main() {
	int* ptr;
	int num;
	int cls;

	cout << "�� ���ΰ���? ";
	cin >> cls;

	cout << "�л��� �� ���ΰ���? ";
	cin >> num;

	ptr = new int[num];
	int sum = 0;
	cout << "������ �Է����ּ���." << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "�� �л��� ����: ";
		cin >> ptr[i]; //*(ptr+1), ptr�� �迭���� ��ó�� ���!
		sum += ptr[i];
	}
	cout << cls << "���� ��� = " << (double)sum / num << endl;
}