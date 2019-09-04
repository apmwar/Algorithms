//https://www.hackerrank.com/challenges/two-arrays/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q;
    cin >> q;
    while(q--){
        int n;
        long int k;
        cin >> n >> k;
        vector<long int> A(n), B(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
        for(int i = 0; i < n; i++)
            cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
        bool flag = 1;
        for(int i = 0; i < n; i++){
            if(A[i] + B[i] < k){
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
