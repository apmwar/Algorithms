//APPLICATION OF KNAPSACK

#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &weights, int n) {
  vector<vector<int> > value;
  value.resize(n + 1);
  for (int i = 0; i <= n; ++i)
    value[i].resize(W + 1);

  for(int i = 0; i <= n; i++)
	value[i][0] = 0;

  for(int i = 0; i < W + 1; i++)
	value[0][i] = 0;

  for(int i = 1; i <= n; i++){
	for(int w = 1; w <= W; w++){
		value[i][w] = value[i - 1][w];
		if(weights[i - 1] <= w){
			int val = value[i-1][w - weights[i - 1]] + weights[i - 1];
			if(val > value[i][w])
				value[i][w] = val;
		}
	}
  }

  /*display the values matrix
  for(int x = 0; x <= n; x++){
	for(int y = 0; y <= W; y++){
		std::cout << value[x][y]<< " ";
	}
  	std::cout << "\n";
  }
  std::cout << "\n";*/
  return value[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> weights[i];
  }
  std::cout << optimal_weight(W, weights, n) << '\n';
}
