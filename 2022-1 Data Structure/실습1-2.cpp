#include <iostream>
using namespace std;

const int StudentNumber = 10;

void main() {
	// StudentNumber ���� ���� ����� ������
	float score[StudentNumber];

	for (int st = 0; st < StudentNumber; st++) {
		cout << st + 1 << "��° �л� ������ �Է��ϼ���. ";
		cout << endl;
		cin >> score[st];
	}

	double sum = 0;

	for (int i = 0; i < StudentNumber; i++)
		sum = sum + score[i]; //���� �����͸� �־�� �ϴϱ�

	double average = sum / StudentNumber; //���� ������ ������ �������� ����@@�߿�@@

	cout << "SUM =" << sum << endl;
	cout << "AVERAGE=" << average << endl;

}
