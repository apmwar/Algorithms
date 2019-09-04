//https://www.hackerrank.com/challenges/fibonacci-modified/problem

#include <iostream>
using namespace std;

void squareadd(int i, int a[][10000], int &ptr){
	int carry = 0, temp, z = ptr, j;
	int b[10000] = {0};
	
	//squaring the value
	for(int k = 0; k <= z; k++){
		for(j = 0; j <= z; j++){
			temp = a[i - 1][k] * a[i-1][j];
			b[j + k] += temp % 10 + carry;
			carry = temp / 10;
			carry += b[j+k] / 10;
			b[j+k] = b[j+k] % 10;
		}
		while(carry != 0){
			b[j + k] += carry % 10;
			carry = carry / 10;
			ptr = j + k;
		}
	}
	
	//now implementing add
	carry = 0;
	for(int x = 0; x <= ptr; x++){
		temp = b[x] + a[i-2][x];
		a[i][x] = temp % 10 + carry;
		carry = temp / 10;;
	}
	while(carry != 0){
		a[i][ptr + 1] = carry % 10;
		carry = carry / 10;
		ptr ++;
	}
}

int main(){
	//accept t1, t2, n
	int t1, t2, n;
	cin >> t1 >> t2 >> n;

	//declare the dp array, initialise
	int a[20][100000] = {0};
	a[0][0] = t1;
	a[1][0] = t2;
	
	int ptr = 0;

	// c = a + b^2
	
	for(int i = 2; i < n; i++){
		// square value of b first then add
		squareadd(i, a, ptr);
		/*for(int j = ptr; j >= 0; j--)
			cout << a[i][j];
		cout << "\n----------------------------------------------------\n\n";*/
	}
	
	//display the resulting array factorial
	 for(int i = ptr; i >= 0; i--)
			cout << a[n - 1][i];
	return 0;
}
