#include <iostream>
using namespace std;

const int StudentNumber = 10;
const int SubjectNumber = 3;

void main() {
	//StudentNumber ���� ���� ����� ������
	float score[SubjectNumber][StudentNumber] = { {56,73,54,90,100,89,23,68,92,30}
		,{80,67,89,90,100,74,45,60,78,50},{96,56,78,73,90,27,84,67,52,100} };

	//���� ���
	for (int subj = 0; subj < SubjectNumber; subj++)
	{
		double sum = 0;

		for (int student = 0; student < StudentNumber; student++)
			sum += score[subj][student];

		double average = sum / StudentNumber;
		cout << subj + 1 << "��° ������ ���: " << average << endl;

	}
	cout << endl;

	//���κ� ���
	for (int student = 0; student < StudentNumber; student++)
	{
		double sum = 0;

		for (int subj = 0; subj < SubjectNumber; subj++)
			sum += score[subj][student];

		double average = sum / SubjectNumber;
		cout << student + 1 << "��° �л��� ���: " << average << endl;
	}
}
