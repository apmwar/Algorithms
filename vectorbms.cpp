#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007
typedef int matrix[3][3];

void multiply(matrix a, matrix b){
    matrix c = {0};
    
/*
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
*/

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                c[i][j] += (a[i][k] *  b[k][j]) % MOD;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            a[i][j] = c[i][j];
    }
}

void fastmatrix(matrix base, unsigned long long power) {
    matrix result = {1, 2, 3, 1, 0, 0, 0, 1, 0};
    while(power) {
        if(power & 1)
            multiply(result, base);
        multiply(base, base);
        power >>= 1; //power = power / 2
    }
}

//exponentiate procedure for n - 3
long long int possibleways(unsigned long long n){
    matrix base = {1, 2, 3, 1, 0, 0, 0, 1, 0};
    int arr[3] = {7, 2, 1};
    fastmatrix(base, n - 4);
    long long int sum = 0;
    for(int i = 0; i < 3; i++)
        sum += (base[0][i] * arr[i]) % MOD;
    return sum % MOD;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned long long h;
		cin >> h;
        if(h == 1)
            cout << "1";
        else if(h == 2)
            cout << "2";
        else if(h == 3)
            cout << "7";
        else
		    cout << possibleways(h);
	}
    return 0;
}
