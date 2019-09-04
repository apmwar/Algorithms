//matrix exponentiation code
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

function recurrent_seq(int N, int k, int arr[], int c[]){ // a and c are arrays of size k
  if N <= k - 1:
    return a[N]
  M = build_M(k, c)
  initial = a // initial vector: (a_0, a_1, …, a_{k-1})
  exp = matrix_power_with_modulo(M, N - k + 1, 1000000007)
  return (initial * exp)[1][k] modulo 1000000007 // initial*exp is a matrix
// (A_{N - k + 1}, A_{N - k + 2}, …, A_N). We take first row,
//last column as the result, which is A_N.
}

int main(){
  unsigned long long h;
  cin >> h;
  int arr[3];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 6;
  int M[3][3] = {1, 1, 1, 1, 0, 0, 0, 1, 0};
  recurrent_seq(h, 3, arr, )
  return 0;
}
