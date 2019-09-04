//https://www.hackerrank.com/challenges/equal/problem


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxormin(vector<int> A, int n){
	int mincount = 0, maxcount = 0;
	int i = 0;
	while(A[i] == A[0]){
		mincount++;
		i++;
	}
	i = n - 1;
	while(A[i] == A[n - 1]){
		maxcount++;
		i--;
	}
	return (maxcount > mincount) ? 1 : 0;
}

void minbalance(vector<int> &A, int n){
	int min = A[0];
	for(int i = 0; i < n; i++)
		A[i] = A[i] - min;
}
void maxbalance(vector<int> &A, int n){
	int max = A[n - 1];
	int i = n - 1;
	while(A[i] - max == 0){
		A[i] = A[i] - max;
		i--;
	}
}

int min(int a, int b, int c){
	if(a <= b){
		if(a <= c)
			return a;
		else
			return c;
	}
	else if(b <= c){
		return b;
	}
	return c;
}

void fillarray(int array[]){
	for(int i = 6; i < 1000; i ++){
		int a = 1 + array[i - 1];
		int b = 1 + array[i - 2];
		int c = 1 + array[i - 5];
		array[i] = min(a, b, c);
	}
}

int main() {
    int t;
    cin >> t;
    //dp array
	int array[1000];
	array[0] = 0;
	array[1] = 1;
	array[2] = 1;
	array[3] = 2;
	array[4] = 2;
	array[5] = 1;
	fillarray(array);
	
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
            
		//sort the array
		sort(A.begin(), A.end());
		int x = maxormin(A, n);
		int min = A[0];
		int max = A[n - 1];
		long long int count = 0;
		if(x == 0){
			minbalance(A, n);
			for(int i = 0; i < n; i++){
				count += array[A[i]];
			}
		}
		else{
			maxbalance(A,n);
			for(int i = 0; i < n; i++){
				if(A[i] != 0)
					count += array[max - A[i]];
			}
		}
		cout << count << endl;
    }
    return 0;
}

