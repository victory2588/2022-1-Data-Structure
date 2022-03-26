#include <iostream>
using namespace std;

void main() {
	int* ptr;
	int num;
	int cls;

	cout << "몇 반인가요? ";
	cin >> cls;

	cout << "학생은 몇 명인가요? ";
	cin >> num;

	ptr = new int[num];
	int sum = 0;
	cout << "성적을 입력해주세요." << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "번 학생의 점수: ";
		cin >> ptr[i]; //*(ptr+1), ptr이 배열명인 것처럼 사용!
		sum += ptr[i];
	}
	cout << cls << "반의 평균 = " << (double)sum / num << endl;
}