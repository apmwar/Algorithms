//competition  entry for _init0_
//https://www.hackerrank.com/contests/-init0-/challenges/vector-and-his-chipsets
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

struct data{
    long long int n;
    int index;
};

bool number_sorter(data const& a, data const& b) {
    return a.n < b.n;
}

long long sumitup(vector<struct data> &A, int n){
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum+= A[i].n;
	return sum;
}

void calcSubset(vector<struct data> &A, int n){
	long long sum = sumitup(A, n);
	long long newsum = 0;
	for(int i = n - 1; i >= 0; i--){
		sum -= A[i].n;
		newsum += A[i].n;
		if(newsum >= sum){
			for(int j = i; j < n; j++)
				cout << A[j].index << " ";
			break;
		}
	}
}

int main() {
    int n;
    cin >> n;
    vector<struct data> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i].n;
        A[i].index = i + 1;
    }
    sort(A.begin(), A.end(), &number_sorter);
	calcSubset(A, n);
    return 0;
}
