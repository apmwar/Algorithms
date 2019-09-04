#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isSubsetSum(vector<int> &set, int n, int sum){
	if(sum == 0)
		return 1;

	if (n == 0 && sum != 0)
     return 0;

   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);

   return isSubsetSum(set, n-1, sum) + isSubsetSum(set, n-1, sum-set[n-1]);

}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> A(n);
  for(int i = 0; i < n; i++)
    cin >> A[i];
	sort(A.begin(), A.end());
	vector<int> dp(m + 1);
	dp[0] = 0;
	for(int i = 1; i <= m; i++){
		dp[i] = isSubsetSum(A, n, i);
	}
	if(dp[m] == 1)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
