#include <climits>
#include <iostream>
#include <vector>

using namespace std;


int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
  int minVal = INT_MAX, minIndex = -1;

  for (int v = 0; v < V; v++) {
    if (!mstSet[v] && key[v] < minVal) {
      minVal = key[v];
      minIndex = v;
    }
  }
  return minIndex;
}


void primMST(const vector<vector<int>>& graph, int V) {
  vector<int> parent(V);
  vector<int> key(V, INT_MAX);
  vector<bool> mstSet(V, false);

  
  key[0] = 0;
  parent[0] = -1; 

  for (int count = 0; count < V - 1; count++) {
    int u = minKey(key, mstSet, V);
    mstSet[u] = true;

   
    for (int v = 0; v < V; v++) {
      if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  
  cout << "Edge \tWeight\n";
  int totalCost = 0;
  for (int i = 1; i < V; i++) {
    cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
    totalCost += graph[i][parent[i]];
  }
  cout << "Total Cost: " << totalCost << "\n";
}

int main() {
  int V = 5;


  vector<vector<int>> graph = {
      {0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 0}, {0, 5, 7, 0, 0}};

  primMST(graph, V);
  return 0;
}
