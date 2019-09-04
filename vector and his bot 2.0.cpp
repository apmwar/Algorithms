#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct coord{
    int x, y;
};

void botDirection(vector<struct coord> &A, int n){
    coord dir, diff, expected;
    dir.x = A[1].x - A[0].x;
    dir.y = A[1].y - A[0].y;
    for(int i = 2; i < n; i++){
        expected.x = A[i-1].x + dir.x;
        expected.y = A[i-1].y + dir.y;
        //cout << "EXPECTED TO REACH:6 " << expected.x << " " << expected.y<< endl;
		//0cout << "NEED TO REACH: " << A[i].x << " " << A[i].y<< endl;
        if(expected.x  == A[i].x && expected. y < A[i].y){
            cout << "Turns Left\n";
        }
        if(expected.y == A[i].y && expected.x > A[i].x){
			cout << "Turns Left\n";
		}
		else if(expected.x == A[i].x && expected.y > A[i].y){
			cout << "Turns Rigth\n";
		}
        else if(expected.y == A[i].y && expected. x < A[i].x){
            cout << "Turns Rigth\n";
        }
        else if(expected.x == A[i].x && expected.y == A[i].y)
            cout << "Goes Straight\n";
        dir.x = A[i].x - A[i-1].x;
        dir.y = A[i].y - A[i-1].y;
    }

}

int main() {
    int n;
    cin >> n;
    vector<struct coord> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i].x >> A[i].y;
    botDirection(A, n);
    return 0;
}
