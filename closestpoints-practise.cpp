#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

struct Point {
  int x;
  int y;
};

bool sortx(Point a, Point b) { return a.x < b.x; }

double compute(Point a, Point b) {
  return (double)pow(a.x - b.x, 2) + (double)pow(a.y - b.y, 2);
}

double divide(vector<Point> &A, int l, int r) {
  if(l == r) {
    return -1;
  } else if(l+1 == r) {
    return compute(A[l], A[r]);
  } else if(l+2 == r) {
    return min(min(compute(A[l], A[l+1]), compute(A[l+1], A[l+2])), compute(A[l], A[l+2]));
  } else {
    int mid = (l+r)/2;
    int lmin = divide(A, l, mid);
    int rmin = divide(A, mid+1, r);
    int lrmin = compute(A[mid], A[mid+1]);
    return min(min(lmin, rmin), lrmin);
  }
}

int main() {
  int n;
  cin >> n;
  vector<Point> A(n);
  for(int i = 0; i < n; i++) {
    cin >> A[i].x >> A[i].y;
  }
  sort(A.begin(), A.end(), sortx);
  cout << setprecision(7);
  cout << sqrt(divide(A, 0, n-1));
  return 0;
}
