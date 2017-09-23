#include <iostream>
using namespace std;

#define MOD 1000000007

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power & 1)
            result = (result*base) % MOD;
        base = (base * base) % MOD;
        power >>= 1; //power = power / 2
    }
    return result;
}

int main(){
	cout << fast_power(2, 10000000000000) << " ";
	return 0;
}
