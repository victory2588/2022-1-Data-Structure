#include <iostream>
using namespace std;

const int StudentNumber = 10;
const int SubjectNumber = 3;

void main() {
	//StudentNumber 명의 성적 평균을 구하자
	float score[SubjectNumber][StudentNumber] = { {56,73,54,90,100,89,23,68,92,30}
		,{80,67,89,90,100,74,45,60,78,50},{96,56,78,73,90,27,84,67,52,100} };

	//과목별 평균
	for (int subj = 0; subj < SubjectNumber; subj++)
	{
		double sum = 0;

		for (int student = 0; student < StudentNumber; student++)
			sum += score[subj][student];

		double average = sum / StudentNumber;
		cout << subj + 1 << "번째 과목의 평균: " << average << endl;

	}
	cout << endl;

	//개인별 평균
	for (int student = 0; student < StudentNumber; student++)
	{
		double sum = 0;

		for (int subj = 0; subj < SubjectNumber; subj++)
			sum += score[subj][student];

		double average = sum / SubjectNumber;
		cout << student + 1 << "번째 학생의 평균: " << average << endl;
	}
}
