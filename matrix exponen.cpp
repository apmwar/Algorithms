#include <bits/stdc++.h>
using namespace std;

void multiply(int a[3][3], int b[3][3])
{
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
1
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

#define M 1000000007

int possibleways(int n, long long int dyn[]) {
		if (n < 1) {
			return 0;
		}
		if (dyn[n] > 0) {
			return dyn[n];
		}
		dyn[n] = 1 + possibleways(n - 1, dyn) + possibleways(n - 2, dyn) + possibleways(n - 3, dyn);
		return dyn[n] % M;
	}

int main(){
	long int n = 10;
	long long int dyn[n + 1] = {0};
	dyn[0] = 0;
	dyn[1] = 1;
	dyn[2] = 2;
	dyn[3] = 4;
	cout << possibleways(n, dyn);
}
