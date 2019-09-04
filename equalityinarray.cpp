//https://www.hackerrank.com/challenges/equality-in-a-array/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> A(n), occurance(101);
    for(int i = 0; i < n; i++){
        cin >> A[i];
        occurance[A[i]]++;
    }
    int max = occurance[1];
    for(int i = 1; i <= 100; i ++){
        if(occurance[i] > max)
            max = occurance[i];
    }
    cout << n - max;
    return 0;
}
