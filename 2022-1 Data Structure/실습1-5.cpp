#include <iostream>
using namespace std;

const int cls = 3;
const int subject = 3;
const int st_num = 10;

void main() {
	double scores[cls][subject][st_num] =
	{ {{87,90,56,77,96,39,88,92,34,100},
		{87,80,33,45,68,98,56,77,100,23},
		{92,64,88,98,99,63,42,12,34,67}},
		{{90,87,65,54,23,56,88,90,100,22},
		{80,56,87,98,100,14,35,66,83,89},
		{90,10,56,88,90,30,56,89,87,99}},
		{{100,50,43,24,78,96,36,98,100,76},
		{90,44,60,7,100,98,65,78,98,100},
		{98,85,42,64,56,78,99,12,48,90}}
	};

	//각 반별, 과목별 평균값
	for (int cl = 0; cl < cls; cl++) {
		for (int sbj = 0; sbj < subject; sbj++) {
			double sum = 0;
			for (int st = 0; st < st_num; st++) {
				sum += scores[cl][sbj][st];
			}
			double average = sum / st_num;

			cout << cl + 1 << "반의" << sbj + 1 << "번째 과목의 평균은" << average << endl;

		}
	}

	//해당 학년의 과목 평균
	for (int sbj = 0; sbj < subject; sbj++) {
		double sum = 0; //sum의 위치 잘 잡기!!
		for (int cl = 0; cl < cls; cl++) {
			for (int st = 0; st < st_num; st++) {
				sum += scores[cl][sbj][st];
			}
		}
		double average = sum / (st_num * 3);
		cout << "3학년의" << sbj + 1 << "번째 과목의 평균은" << average << endl;
	}

}
