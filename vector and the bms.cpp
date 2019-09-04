#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

void multiply(int a[3][3], int b[3][3]) {
    int mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];
}

int power(int F[3][3], int n)
{
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
    if (n==1)
        return F[0][0] + F[0][1];

    power(F, n/2);
    multiply(F, F);
    if (n%2 != 0)
        multiply(F, M);
    return F[0][0] + F[0][1] ;
}

int findNthTerm(int n)
{
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
    return power(F, n-2);
}
int possibleways(int n, long long int dyn[]) {
	if (n < 1) {
		return 0;
	}
	if (dyn[n] > 0) {
		return dyn[n];
	}
	dyn[n] = possibleways(n - 1, dyn) + 2 * possibleways(n - 2, dyn) + 3*possibleways(n - 3, dyn);
	return dyn[n] % MOD;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned long long h;
		cin >> h;
		long long int dyn[h+1];
		dyn[0] = 0;
		dyn[1] = 1;
		dyn[2] = 2;
		dyn[3] = 7;
		cout << possibleways(h, dyn);
	}
}
