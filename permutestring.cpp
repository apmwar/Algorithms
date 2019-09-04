#include <iostream>
#include <string>
using namespace std;

void swap(string &s, int i, int j) {
  char temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

void permute(string &s, int l, int r) {
  if(l == r-1) {
    cout << s << endl;
  }
  else {
    for(int i = l; i < r; i++) {
      swap(s, l, i);
      permute(s, l+1, r);
      swap(s, l, i);
    }
  }

}

int main() {
  string s;
  cin >> s;
  permute(s, 0, s.size());
  return 0;
}
