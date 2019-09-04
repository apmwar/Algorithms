#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long int> > matrix;
#define MOD 1000000007

//procedure to calculate the multiplication of matrix
matrix multiply(matrix A, matrix B){
  matrix C(3, vector<long int>(3));
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return C;
}

//procedure to do the fast multiplication procedure
matrix fast_mat_mul(matrix M, unsigned long long N){
  if(N == 1)
    return M;
  if(N & 1) // N is odd
    multiply(M, fast_mat_mul(M, N - 1));
  matrix X = fast_mat_mul(M, N / 2);
  return multiply(X, X);
}

//procedure to do the assigning and other stuff
void no_of_ways(unsigned long long N){
  matrix M(3, vector<long int> (3));
  M[0][0] = 1; M[0][1] = 1; M[0][2] = 3;
  M[1][0] = 1; M[1][1] = 0; M[1][2] = 0;
  M[2][0] = 0; M[0][1] = 1; M[2][2] = 0;

  int F[3] = {6,2,1};
  M = fast_mat_mul(M, N);
  long long int ways = 0;
  for(int i = 0; i < 3; i++){
    ways = (ways + (M[0][i] * F[i])) % MOD;
  }
  cout << ways << endl;
}


int main(){
  int t;
  cin >> t;
  while(t--){
    unsigned long long h;
    cin >> h;
    if(h == 1){
      cout << "1\n";
    }
    else if(h == 2){
      cout << "2\n";
    }
    else if(h == 3){
      cout << "3\n";
    }
    else{
      no_of_ways(h - 3);
    }
  }
  return 0;
}
