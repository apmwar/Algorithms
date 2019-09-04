#include<iostream>
#include<vector>
using namespace std;

long long int pairwise(vector <int> &a, int n){
	for(int j = 0;j < 2;j++){
		for(int i = 0;i < n-j-1;i++){
			if(a[i] > a[i+1]){
				a[i]+= a[i+1];
				a[i+1] = a[i] - a[i+1];
				a[i] -= a[i+1];
			}
		}
	}
	return (long long)a[n-1]*(long long)a[n-2];
}
int main(){
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0;i < n;i++)
		cin >> a[i];
	long long int pprod = pairwise(a,n);
	cout << pprod << endl;
	return 0;
}
