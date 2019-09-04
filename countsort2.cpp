#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void countsort1(vector<int> &a, int n){
    int copy[10] = {0};
    for(int i = 0; i < n; i++){
        int temp = a[i];
        copy[temp]++;
    }
    for(int i = 0; i < 10; i++){
	while(copy[i] > 0){
		cout << i << " ";
		copy[i]--;
	}
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    countsort1(a, n);
    return 0;
}

