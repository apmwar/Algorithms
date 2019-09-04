#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void lcs(string A, string B, int m, int n) {
	int LCS[m+1][n+1];
  	for(int i = 0; i <= m; i++) {
    	for(int j = 0; j <= n; j++) {
        	if(i == 0 || j == 0) {
            	LCS[i][j] = 0;
            } else if(A[i-1] == B[j-1]){
            	LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
            	LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
  	int i = m, j = n, k = LCS[m][n];
  	char result[k];
  	while(i > 0 && j > 0) {
    	if(A[i-1] == B[j-1]) {
        	result[--k] = A[i-1];
          	i--; j--;
        } else if(LCS[i-1][j] > LCS[i][j-1]) {
        	i--;
        } else {
        	j--;
        }
    }
  	for(int ii = 0; ii < LCS[m][n]; ii++) { cout << result[ii]; }
}

int main()
{
	string a, b;
  	cin >> a >> b;
  	cout << "The Longest Common Subsequence is ";
    lcs(a, b, a.length(), b.length());
	return 0;
}
