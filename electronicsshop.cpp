//https://www.hackerrank.com/challenges/electronics-shop/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int m, n, s;
    cin >> s >> n >> m;
    vector<int> key(n), usb(m);
    for(int i = 0; i < n; i++)
        cin >> key[i];
    for(int j = 0; j < m; j++)
        cin >> usb[j];
    sort(key.begin(), key.end());
    sort(usb.begin(), usb.end());
    //procedure
    int cost = -1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            int a = key[i] + usb[j];
            if(a <= s)
                if(a > cost)
                    cost = a;
        }
    }
    //print statement
    cout << cost;
    return 0;
}
