#include <iostream>
using namespace std;

const int StudentNumber = 10;

void main() {
	// StudentNumber 명의 성적 평균을 구하자
	float score[StudentNumber];

	for (int st = 0; st < StudentNumber; st++) {
		cout << st + 1 << "번째 학생 성적을 입력하세요. ";
		cout << endl;
		cin >> score[st];
	}

	double sum = 0;

	for (int i = 0; i < StudentNumber; i++)
		sum = sum + score[i]; //성적 데이터를 넣어야 하니까

	double average = sum / StudentNumber; //정수 나누기 정수는 정수값만 나옴@@중요@@

	cout << "SUM =" << sum << endl;
	cout << "AVERAGE=" << average << endl;

}
