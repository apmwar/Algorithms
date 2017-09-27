#include <iostream>
using namespace std;

int a[] = {1,2,3,4};
int b[] = {5,6,7,8};
int c[7] = {0};

void mult(int n, int al, int bl){
	if(n == 1)
		c[al + bl] += a[al] * b[bl];
	else{
		mult(n/2, al, bl);
		mult(n/2, al + n / 2, bl + n / 2);
		mult(n/2, al, bl + n / 2);
		mult(n/2, al + n / 2, bl);
	}
		
}
int main(){
	mult(4, 0 , 0);
	for(int i = 0; i < 7; i++)
		cout << c[i] <<" ";
	return 0;
}
