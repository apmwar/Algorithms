#include <map>
#include <iostream>
using namespace std;
map<long long,long long>F;

long long f(long long n, long long m) {
	if (F.count(n))
		return F[n];
	long long k = n / 2;
	if (n % 2 == 0) { // n=2*k
		return F[n] = (f(k,m)*f(k,m) + f(k-1,m)*f(k-1,m)) % m;
	} else { // n=2*k+1
		return F[n] = (f(k,m)*f(k+1,m) + f(k-1,m)*f(k,m)) % m;
	}
}

int main(){
	long long n,m;
	F[0]=F[1]=1;
	cin >> n >> m;
	cout << (n==0 ? 0 : f(n-1,m)) << endl;
	return 0;
}
