#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


struct Edge {
  int u, v, weight;

  bool operator<(const Edge& other) const { return weight < other.weight; }
};


struct DSU {
  vector<int> parent;
  vector<int> rank;

  DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
  }

 
  int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
  }

  
  bool unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);

    if (root_i != root_j) {
      if (rank[root_i] < rank[root_j]) {
        parent[root_i] = root_j;
      } else if (rank[root_i] > rank[root_j]) {
        parent[root_j] = root_i;
      } else {
        parent[root_j] = root_i;
        rank[root_i]++;
      }
      return true;  // Successfully merged (no cycle)
    }
    return false;  // Already in the same set (forms a cycle)
  }
};

void kruskalMST(int V, vector<Edge>& edges) {
  // Step 1: Sort all edges in non-decreasing order of their weight
  sort(edges.begin(), edges.end());

  DSU dsu(V);
  vector<Edge> mst;
  int totalCost = 0;

  // Step 2: Iterate through sorted edges
  for (const auto& edge : edges) {
    if (dsu.unite(edge.u, edge.v)) {
      mst.push_back(edge);
      totalCost += edge.weight;

      // An MST with V vertices always has V-1 edges
      if (mst.size() == V - 1) break;
    }
  }

  // Print the resulting MST edges and total cost
  cout << "Edge \tWeight\n";
  for (const auto& edge : mst) {
    cout << edge.u << " - " << edge.v << " \t" << edge.weight << "\n";
  }
  cout << "Total Cost: " << totalCost << "\n";
}

int main() {
  int V = 5;

  // Graph represented as a list of edges (u, v, weight)
  vector<Edge> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};

  kruskalMST(V, edges);
  return 0;
}
