#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findmin(int l, int r, vector<int> &A){
  if(l == r)
    return A[l];
  else if(l+1 == r)
    return (A[l] > A[r]) ? A[r] : A[l];
}

int findmax(int l, int r, vector<int> &A){
  if(l == r)
    return A[l];
  else if(l+1 == r)
    return (A[l] < A[r]) ? A[r] : A[l];
}

int mindc(int l, int r, vector<int> &A){
  int mid = (l+r)/2;
  int a = findmin(l, mid - 1, A);
  int b = findmin(mid, r - 1, A);
  return (a < b) ? a : b;
}

int maxdc(int l, int r, vector<int> &A){
  int mid = (l+r)/2;
  int a = findmax(l, mid - 1, A);
  int b = findmax(mid, r - 1, A);
  return (a > b) ? a : b;
}

int main()
{
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++)
    cin >> A[i];
  int min, max;
  min = mindc(0, n, A);
  max = maxdc(0, n, A);
  cout << "Minimum element is " << min << endl;
  cout << "Maximum element is " << max << endl;
  return 0;
}
