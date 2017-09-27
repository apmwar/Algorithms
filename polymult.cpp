#include <iostream>
#include <vector>
using namespace std;
int main(){
	int a[] = {1,2,3,4}, b[] = {5,6,7,8};
	int prod[7] = {0};
	for(int i = 0; i < 4; i ++){
		for(int j = 0; j < 4; j++){
			prod[i + j] += a[i] * b[j];
		}
	}
	for(int i = 0; i < 7; i++)
		cout << prod[i] <<" ";
	return 0;
}
