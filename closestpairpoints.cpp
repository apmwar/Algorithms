#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits.h>
using namespace std;

struct Point{
	int x;
  	int y;
};

bool xcompare(Point a, Point b) { return a.x < b.x; }

double compute(Point a, Point b){
	return pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
}

double divide(vector<Point> &A, int l, int r){
  	if(l == r) { //size is 1
    	return INT_MAX;
    } else if(l+1 == r) { //size 2
    	return compute(A[l], A[r]);
    } else if(l+2 == r) { //size 3
    	return min(min(compute(A[l], A[l+1]), compute(A[l+1], A[r])), compute(A[r], A[l]));
    } else {
      int mid = (l+r)/2;
      double lmin = divide(A, l, mid - 1);
      double rmin = divide(A, mid, r - 1);
      double lrmin = compute(A[mid - 1], A[mid]);
       return min(min(lmin, rmin), lrmin);
    }
}

int main()
{
	int n;
  	cin >> n;
  	vector<Point> A(n);
  	for(int i = 0; i < n; i++)
    	cin >> A[i].x >> A[i].y;
  	sort(A.begin(), A.end(), xcompare);
  	cout << setprecision(7) << sqrt(divide(A, 0, n-1));
	return 0;
}
l
