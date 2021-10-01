#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <queue>
using namespace std;

const int I = INT_MAX; // infinity for int

typedef tuple<int, int, int> Edge;

class compareEdge {
  public:
    bool operator()(Edge e1, Edge e2) {
      return (get<2>(e1) > get<2>(e2));
    }
};

class DisjointSet {
  public:
    vector<int> set;

    DisjointSet(int size): set(size, -1) {}

    void Union(int u, int v) {
      if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
      } else {
        set[v] += set[u];
        set[u] = v;
      }
    }

    int find(int n) {
      int x = n;

      while (set[x] > 0) {
        x = set[x];
      }

      if (n != x)
        set[n] = x;
      
      return x;
    }
};

vector<pair<int, int>> kruskals(vector<vector<int>> graph) {
  priority_queue<Edge, vector<Edge>, compareEdge> heap;
  const int N = graph.size() - 1; // number of vertices
  DisjointSet set(N+1); // size = N+1 because N vertices (1 to N) and 0th empty
  vector<pair<int, int>> MST;

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=i; j++) {
      if (graph[i][j] != I) {
        heap.push(make_tuple(i, j, graph[i][j]));
      }
    }
  }

  // there will be N-1 edges in MST
  for (int i=0; !heap.empty() && i<N-1;) {
    Edge minEdge = heap.top();
    heap.pop();
    
    int u = get<0>(minEdge);
    int v = get<1>(minEdge);
    
    int x = set.find(u);
    int y = set.find(v);

    if (x != y) {
      MST.push_back({u, v});
      set.Union(x, y);
      i++;
    }
  }

  return MST;
}

int main() {
  vector<vector<int>> graph = {
    {I, I, I, I, I, I, I, I, I, I},
    {I, I, 8, I, I, I, I, 11, I, 4},
    {I, 8, I, 7, I, 4, I, I, 2, I},
    {I, I, 7, I, 9, 14, I, I, I, I},
    {I, I, I, 9, I, 10, I, I, I, I},
    {I, I, 4, 14, 10, I, 2, I, I, I},
    {I, I, I, I, I, 2, I, 1, 6, I},
    {I, 11, I, I, I, I, 1, I, 7, 8},
    {I, I, 2, I, I, I, 6, 7, I, I},
    {I, 4, I, I, I, I, I, 8, I, I}
  };

  // for (auto row: graph) {
  //   for (auto ele: row) {
  //     if (ele == I)
  //       cout << "I ";
  //     else
  //       cout << ele << " ";
  //   }
  //   cout << "\n";
  // }

  vector<pair<int, int>> MST = kruskals(graph);

  int cost = 0;
  for (auto edge: MST) {
    cout << edge.first << " --(" << graph[edge.first][edge.second] << ")--> " << edge.second << endl;
    cost += graph[edge.first][edge.second];
  }
  cout << "Total cost of MST: " << cost;

  return 0;
}
