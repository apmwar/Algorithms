#include <iostream>
using namespace std;

int setBits(int n) {
  int count = 0;
  //cout << n;
  while(n > 1) {
    if(n % 2 == 0) {
      while(n%2 == 0) {
        n = n/2;
      }
    } else {
      count++;
      n--;
    }
  }
  count++;
  //cout << " has " << count << " set bits\n";
  return count;
}

int setBitCount(int n) {
  int i = 2;
  int sum = 1;
  while(i <= n) {
    sum += setBits(i);
    i++;
  }
  return sum;
}

int main() {
  int n = 8;
  cout << "Total set bit count is " << setBitCount(n);
  return 0;
}

/*
0001
0010
0011
0100
0101
0110
0111
1000
*/
