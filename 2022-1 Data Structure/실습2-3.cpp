#include <iostream>
using namespace std;

void main() {
	int scores[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int* ptr;

	ptr = scores; //오잉? 싶지만 맞음

	//ptr++; 얘는 가능
	//scores++; 얘는 배열명이라는 책임감이 있어서 함부로 바뀌면 안됨

	for (int i = 0; i < 10; i++) {
		cout << *(ptr + i) << endl;
		//cout << *(ptr++) << endl; 이것도됨
		cout << ptr[i] << endl; //이런 표현방법을 혼용해서 쓴다! 익숙해지도록 공부
		//크게 위의 3가지 정도로 표현하는듯
		cout << *(scores + i) << endl;
		cout << scores[i] << endl;
	}
}