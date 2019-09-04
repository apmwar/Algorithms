#include <iostream>
#include <cmath>
using namespace std;

void nextHigher(int a) {
  string s;
  int i = 0, totalbits = 0;
  while(pow(2, i) < a) {
    totalbits++;
    i++;
  }
  cout << "Total bits is " << totalbits;
}

int main() {
  int a = 153;
  nextHigher(a);
  return 0;
}
