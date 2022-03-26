#include <iostream>
using namespace std;

void main() {
	char A[4] = { 'T','I' }; //이건 4개짜리 배열이 맞음
	char A[] = { 'T','I' }; //이건 오류남. 문자를 계속 찍음
	char B[] = "TI"; //{ 'T','I','\0' }과 같음
	cout << A;
	cout << B;

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << strlen(B) << endl;


}