#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, int n, const vector<int> &w, const vector<int> &v) {
  vector<int> value(W+1);
  int temp;
  value[0] = 0;
  for(int i = 1; i <= W; i++){
	value[i] = 0;
	for(int j = 0; j < n; j++){
		if(w[j] <= i)
			temp = value[i - w[j]] + v[j];
		if(temp > value[i])
			value[i] = temp;

	}
  }
  return value[W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n), v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i] >> v[i];
  }
  std::cout << std::endl;
  std::cout << optimal_weight(W, n, w, v) << '\n';
}
