#include <iostream>
using namespace std;

int sumOfSubsets(int A[], int n, int k, int i, int sum) {
  if(i < n) {
    if(sum + A[i] == k) {
      return 1;
    } else if(sum+A[i] > k) {
      return 0;
    } else {
      return sumOfSubsets(A, n, k, i+1, sum+A[i]) + sumOfSubsets(A, n, k, i+1, sum);
    }
  }
}


int main() {
  int n = 4;
  int A[] = {1, 2, 3, 4};
  int k = 4;
  cout << sumOfSubsets(A, n, k, 0, 0);
  return 0;
}
