#include <iostream>
#include <cmath>
using namespace std;

long long int gcd(long long int a, long long int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main(){
    long long int a, b;
    cin >> a >> b;
    long long int n = gcd(a, b);
    int result = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(n / i == i)
                result++;
            else
                result += 2;
        }
    }
    cout << result;
    return 0;
}
