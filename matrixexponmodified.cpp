#include <iostream>
#include <vector>
#define MOD 1000000007
const int k = 3;
typedef vector<vector<long long>> matrix;
using namespace std;

int main(){
  unsigned long long N;
  cin >> N;
  long long x = ways(N - k + 1);
  cout << x;
  return 0;
}
