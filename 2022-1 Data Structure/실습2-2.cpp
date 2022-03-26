#include <iostream>
using namespace std;

/*void main() {
	int scores[10];

	cout << scores << endl;
	cout << &scores << endl;
	cout << &scores[0] << endl;
	cout << &scores[1] << endl; //위의 결과보다 4가 크게 나옴

} //배열명만 찍으면 주소가 나옴!*/

void main() {
	int scores[10] = { 10,20,30,40,50,60,70,80,90,100 };

	cout << scores << endl;
	cout << &scores << endl;
	cout << &scores[0] << endl;

	for (int i = 0; i < 10; i++) {
		//cout << *(scores+i) << endl; 이런 식의 표현과 익숙해져야함
		cout << scores[i] << endl; //라고 작성해도 컴퓨터는 위처럼 다 바꿈
	}
}