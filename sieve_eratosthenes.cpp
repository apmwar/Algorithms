#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main() {
    vector<int> A(MAX+1);
    
    int n = sqrt(MAX);
    
    for(int i = 2; i <= n; i++) {
        if(A[i] == 0) {
            for(int j = i*i; j <= MAX; j+= i) {
                A[j] = 1;
            }
        }
    }
    
    int N;
    cin >> N;
    
    int count = 0;
    
    for(int i = 2; i <= N; i++) {
        if(A[i] == 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}