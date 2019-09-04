//https://www.hackerrank.com/challenges/caesar-cipher-1/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    k = k % 26;
    for(int i = 0; i < n; i++){
        if(s[i] > 64 && s[i] < 91){
            if(s[i] + k > 90){
                s[i] = s[i] - 26 + k;
            }
            else
                s[i] += k;
        }
        else if(s[i] > 96 && s[i] < 123){
            if(s[i] + k > 122){
                s[i] = s[i] - 26 + k;
            }
            else
                s[i] += k;
        }
    }
    cout << s;
    return 0;
}
