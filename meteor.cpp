#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x;
  	int y;
};

bool sortx(Point a, Point b){ return a.x < b.x; }

int main(){
	int t;
  cin >> t;
  while(t--){
		int n, m, q;
	   cin >> n >> m >> q;
		vector<Point> A(q+2);
		A[0].x = A[0].y = 1;
		A[q+1].x = m;
		A[q+1].y = n;
    for(int i = 1; i <= q; i++)
			cin >> A[i].x >> A[i].y;
		sort(A.begin(), A.end(), sortx);
		for(int i = 0; i < q + 2; i++)
			cout << A[i].x << " " << A[i].y << endl;
    }
	return 0;
}
