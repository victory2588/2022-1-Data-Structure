#include <iostream>
using namespace std;

void main() {
	int score[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };

	cout << score << ": " << &score << ": " << &score[0][0] << endl;
	cout << "----------------------------------------" << endl;
	cout << score << ": " << score + 1 << ": " << score + 2 << endl; //score+3�� 4��° �� �ּҴϱ� ����
	//�� 16�� �����ϳ�? -> �� ���ҿ� �� 4���� ���Ҹ� ������ �����ϱ� 4X4
	cout << "----------------------------------------" << endl;
	cout << *(score + 0) << ": " << *(score + 1) << ": " << *(score + 2) << endl;
	cout << "----------------------------------------" << endl;
	cout << score[0] << ": " << score[1] << ": " << score[2] << endl; //*(score+i) ==== score[i] 1���������� ����, 2���������� �ּ�

	cout << *score[0] << ": " << *score[1] << ": " << *score[2] << endl; //�� ���� ù��° ����
	cout << *(score[0] + 1) << ": " << *(score[1] + 1) << ": " << *(score[2] + 1) << endl; //�� ���� �ι�° ����
}