#include <iostream>
using namespace std;

void main() {
	// 10명의 성적 평균을 구하자
	// 1. 성적이 정수일까? 
	int score[10] = { 100,92,79,90,100,90,80,100,92,78 };

	double sum = 0;
	for (int i = 0; i < 10; i++)
		sum = sum + score[i]; //성적 데이터를 넣어야 하니까

	double average = sum / 10; //정수 나누기 정수는 정수값만 나옴@@중요@@
	//처음부터 sum이 double 이었으면 결과 잘 나옴
	cout << "SUM =" << sum << endl;
	cout << "AVERAGE=" << average << endl;

}