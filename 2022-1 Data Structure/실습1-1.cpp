#include <iostream>
using namespace std;

void main() {
	// 10���� ���� ����� ������
	// 1. ������ �����ϱ�? 
	int score[10] = { 100,92,79,90,100,90,80,100,92,78 };

	double sum = 0;
	for (int i = 0; i < 10; i++)
		sum = sum + score[i]; //���� �����͸� �־�� �ϴϱ�

	double average = sum / 10; //���� ������ ������ �������� ����@@�߿�@@
	//ó������ sum�� double �̾����� ��� �� ����
	cout << "SUM =" << sum << endl;
	cout << "AVERAGE=" << average << endl;

}