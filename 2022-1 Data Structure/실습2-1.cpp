#include <iostream>
using namespace std;

void swap(int* x, int* y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp; //주소를 이용하는거니까 i,j값이 근복적으로 바뀜
}

void main() {
	int i = 20;
	int j = 40;

	swap(&i, &j); // i와 j의 주소를 넘겨줌

	cout << i;
	cout << j;
}

/*void main(){
	int data;

	scanf("%d",&data); //swap과 같은 이유로 &data라고 써야됨
	printf("%d",data);
}*/