//fast exponentiation
#include <iostream>
#define MOD 1000000007
using namespace std;

long int power(int a, long long int n){
  if(n == 0)
    return 1;
  else if(n == 1)
    return a;
  else{
    long int R = power(a, n/2);
    if(n % 2 == 0)
      return R * R % MOD;
    else
      return R * R * a % MOD;
  }
}

int main(void){
  int a;
  long long int n;
  cin >> a >> n;
  //we want to compute a^n = x
  long int x = power(a, n);
  cout << x << endl;
}
