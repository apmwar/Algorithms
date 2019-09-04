//https://www.hackerrank.com/challenges/fibonacci-modified/problem

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void squareadd(int a[], int &ptr){
	cout << "SQUARING...\n";
	int carry = 0, temp;
	int b[100] = {0};
	for(int i = 0; i <= ptr; i++){
		b[i] = a[i];
	}
	for(int k = 0; k <= ptr; k++){
		for(int j = 0; j <= ptr; j++){
			temp = a[k] * b[j];
			a[j + k] = temp % 10 + carry;
			carry = temp / 10;
		}
	}
	while(carry != 0){
		a[ptr + 1] = carry % 10;
		carry = carry / 10;
		ptr ++;
	}
}

void add(int i, int a[][100], int &ptr){
	cout << "ADDING...\n";
	int temp, carry = 0;
	for(int x = 0; x <= ptr; x++){
		temp = a[i-1][x] + a[i-2][x];
		a[i][x] = temp % 10 + carry;
		carry = temp / 10;
		cout << a[i][x];
	}
	while(carry != 0){
		a[i][ptr + 1] = carry % 10;
		carry = carry / 10;
		ptr ++;
	}
	cout << endl;
}


int main(){
	//accept t1, t2, n
	int t1, t2, n;
	cin >> t1 >> t2 >> n;

	//declare the dp array, initialise
	int a[20][100] = {0};
	a[0][0] = t1;
	a[1][0] = t2;
	
	int ptr = 0;

	// c = a + b^2
	
	for(int i = 2; i < n; i++){
		// square value of b first
		squareadd(a[i - 1], ptr);
		for(int j = ptr; j >= 0; j--)
			cout << a[i - 1][j];
		// add a and b^2 to c
		add(i, a, ptr);
		cout << "PTR = " << ptr << " ";
		for(int j = ptr; j >= 0; j--)
			cout << a[i][j];
	}
	
	//display the resulting array factorial
	for(int i = ptr; i >= 0; i--)
		cout << a[n - 1][i];
		
	return 0;
}
