#include <iostream>
using namespace std;

void main() {
	int score[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };

	cout << score << ": " << &score << ": " << &score[0][0] << endl;
	cout << "----------------------------------------" << endl;
	cout << score << ": " << score + 1 << ": " << score + 2 << endl; //score+3은 4번째 행 주소니까 오류
	//왜 16씩 증가하나? -> 한 원소에 또 4개의 원소를 가지고 있으니까 4X4
	cout << "----------------------------------------" << endl;
	cout << *(score + 0) << ": " << *(score + 1) << ": " << *(score + 2) << endl;
	cout << "----------------------------------------" << endl;
	cout << score[0] << ": " << score[1] << ": " << score[2] << endl; //*(score+i) ==== score[i] 1차원에서는 원소, 2차원에서는 주소

	cout << *score[0] << ": " << *score[1] << ": " << *score[2] << endl; //각 행의 첫번째 원소
	cout << *(score[0] + 1) << ": " << *(score[1] + 1) << ": " << *(score[2] + 1) << endl; //각 행의 두번째 원소
}