#include <iostream>
using namespace std;

int G[10][10];

void graphcolor(int V) {
  int color[V];
  for(int i = 0; i < V; i++)
    color[i] = 1;
  for(int i = 1; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if(G[i][j] == 1 && color[i] == color[j]) {
        color[i] = color[j]+1;
      }
    }
  }

  for(int i = 0; i < V; i++) {
    cout << "Vertex[" << i << "] : Color #" << color[i] << endl;
  }
}

int main() {
  int E, V;
  cin >> V >> E;
  for(int i = 0; i < E; i++) {
    int x, y;
    cin >> x >> y;
    G[x][y] = G[y][x] = 1;
  }
  graphcolor(V);
  return 0;
}
