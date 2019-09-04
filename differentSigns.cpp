#include <iostream>
using namespace std;

bool diffSigns(int x, int y) {
  return (x^y < 0);
}

int main() {
  int x, y;
  x = 100;
  y = -190;
  if(diffSigns(x, y)) {
    cout << "Signs are opposite";
  } else {
    cout << "Signs are not opposite";
  }
  return 0;
}
