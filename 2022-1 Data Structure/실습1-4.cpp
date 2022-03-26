#include <iostream>
using namespace std;

const int year = 3;
const int period = 4;

void main() {
	double sales[year][period] = { {6,6.5,6.2,7}, {7,6.5,7.5,8}, {9,8.5,9,11} };

	//년도별 매출 총액을 구하자
	for (int y = 0; y < year; y++) {
		double sales_total = 0;

		for (int p = 0; p < period; p++) {
			sales_total += sales[y][p];
		}

		cout << y + 1 << "번째 년도 총 매출액은 " << sales_total << "백만원" << endl;
	}

	//분기별 매출 평균
	for (int p = 0; p < period; p++) {
		double sum = 0;
		//분기별 합계
		for (int y = 0; y < year; y++)
			sum += sales[y][p];

		double average = sum / year;
		cout << p + 1 << "번째 분기의 평균 매출액은 " << average << "백만원" << endl;
	}
}