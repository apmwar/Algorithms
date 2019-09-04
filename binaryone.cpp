#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct myarray{
	int no;
  int bin1;
};

bool compare(myarray a, myarray b) { return a.bin1 < b.bin1; }

int numberOfOnes(int x){
	if(x == 1)
		return 1;
	else if(x % 2 == 0)
		return 0 + numberOfOnes(x/2);
	else
		return 1 + numberOfOnes((x-1)/2);
}

int main()
{
	int t;
  cin >> t;
  while(t--){
  	int n;
		cin >> n;
		vector<myarray> A(n);
    for(int i = 0; i < n; i++){
      cin >> A[i].no;
			A[i].bin1 = numberOfOnes(A[i].no);
      //cout << numberOfOnes(A[i].no) << endl;
  	}
		sort(A.begin(), A.end(), compare);
		for(int i = 0; i < n; i++){
			cout << A[i].bin1 << " ";
  	}
  }
	return 0;
}
