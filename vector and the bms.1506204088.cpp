#include <iostream>
#include <vector>
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

long int possibleways(unsigned long long h, int dyn[]){

}


int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned long long h;
		cin >> h;
		int dyn[4];
		dyn[0] = 0;
		dyn[1] = 1;
		dyn[2] = 2;
		dyn[3] = 5;
		cout << possibleways(h, dyn);
	}
}
