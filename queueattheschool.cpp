//http://codeforces.com/problemset/problem/266/B
#include <iostream>
using namespace std;

void inQueue(string &Q, int n, int t){
    while(t > 0){
        t--;
        for(int i = 0; i < n - 1; i++)
            if(Q[i] == 'B' && Q[i+1] == 'G'){
                Q[i] = 'G';
                Q[i + 1] = 'B';
                i++;
            }
    }
}


int main(){
    int n, t;
    cin >> n >> t;
    string Q;
    cin >> Q;
    inQueue(Q, n , t);
    cout << Q;
    return 0;
}
