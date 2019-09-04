#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

struct Point{
	int x;
  	int y;
};

bool sortx(Point a, Point b){ return a.x < b.x; }

float compute(Point a, Point b){
	return pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
}

float findmin(int l, int r, vector<Point> &A){
	if(l == r - 1){
		return compute(A[l], A[r]);
	}
}

float divide(int l, int r, vector<Point> &A ){
	float lmin, rmin, lrmin;
	lmin = rmin = lrmin = -1;
	int mid = (l + r)/2;
	lmin = compute(A[0], A[1]);
		lmin = findmin(l, mid - 1, A);
		rmin = findmin(mid, r - 1, A);
		float lrmin = compute(A[mid - 1], A[mid]);
		cout << lmin << " " << rmin << " " << lrmin << endl;

		if(lmin < rmin && lmin < lrmin)
			return lmin;
		else if(rmin < lrmin)
			return rmin;
		else
			return lrmin;
}

int main()
{
	int n;
  	cin >> n;
  	vector<Point> A(n);
  	for(int i = 0; i < n; i++)
    	cin >> A[i].x >> A[i].y;
  	sort(A.begin(), A.end(), sortx);
  	//for(int i = 0; i < n; i++) { cout << A[i].x << " " << A[i].y << "\n"; }
		cout << (float)sqrt(divide(0, n, A));
	return 0;
}
