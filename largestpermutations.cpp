//https://www.hackerrank.com/challenges/largest-permutation/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int n, k;
    cin >> n >> k;
    vector <int> a(n), index(n + 1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        index[a[i]] = i;
    }
    /*
    cout << "index array: ";
    for(int i = 1; i <= n; i++)
        cout << index[i] << " ";
    */
    if(k > n)
       k = n;
    for(int i = 0; i < k; i++){
        index[a[i]] = index[ n - i];
        a[index[n - i]] = a[i];
        index[n - i] = i;
        a[i] = n - i;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
