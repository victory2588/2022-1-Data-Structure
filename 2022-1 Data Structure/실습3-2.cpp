#include <iostream>
using namespace std;

void main() {
	char A[4] = { 'T','I' }; //�̰� 4��¥�� �迭�� ����
	char A[] = { 'T','I' }; //�̰� ������. ���ڸ� ��� ����
	char B[] = "TI"; //{ 'T','I','\0' }�� ����
	cout << A;
	cout << B;

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << strlen(B) << endl;


}