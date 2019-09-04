#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int generatePrime(int a[]){
	a[0] = 2;
	a[1] = 3;
	int k = 1;
	for(int i = 5; i < 100; i += 2){
		bool prime = 1;
		for(int j = 1; j <= k; j++){
			if(i % a[j] == 0){
				prime = 0;
				break;
			}
		}
		if(prime == 1){
			a[k + 1] = i;
			k++;
		}
	}
	return k;
}

int getProduct(int a[], unsigned long long n, int length){
	int count = 0;
	int i = 0;
	unsigned long long x = 1;
	while(x * a[i] <= n){
		x *= a[i];
		i++;
		count++;
	}
	return count;
}

int main() {
	int a[20];
	int alen = generatePrime(a);
	int q;
	cin >> q;
	while(q--){
		unsigned long long n;
		cin >> n;
		if(n == 1)
			cout << "0\n";
		else
			cout << getProduct(a, n, alen) << endl;
	}
    return 0;
}

