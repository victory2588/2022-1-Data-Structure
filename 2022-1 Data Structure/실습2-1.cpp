#include <iostream>
using namespace std;

void swap(int* x, int* y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp; //�ּҸ� �̿��ϴ°Ŵϱ� i,j���� �ٺ������� �ٲ�
}

void main() {
	int i = 20;
	int j = 40;

	swap(&i, &j); // i�� j�� �ּҸ� �Ѱ���

	cout << i;
	cout << j;
}

/*void main(){
	int data;

	scanf("%d",&data); //swap�� ���� ������ &data��� ��ߵ�
	printf("%d",data);
}*/