#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long crossproduct(int A, int B, int C, int D){
	return (A * D - B * C);
}

int main() {
    int n, i;
    cin >> n;
    vector<int> x(n), y(n);
    for(i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(i = 2; i < n; i++){
        long long m = crossproduct(x[i-1] - x[i-2], y[i-1]-y[i-2], x[i]-x[i-2], y[i]-y[i-2]);
        if(m == 0)
            cout << "Goes Straight\n";
        else if(m > 0)
            cout << "Turns Left\n";
        else if(m < 0)
            cout << "Turns Rigth\n";
    }
    return 0;
}

