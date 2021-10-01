#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
  public:
    vector<vector<int>> adjMat;
    int noOfVertices;
  
    Graph(int vertices) {
      noOfVertices = vertices;

      for (int i=0; i<=vertices; i++) {
        vector<int> v(vertices+1);
        adjMat.push_back(v);
      }
    }

    virtual void addEdge(int v1, int v2, int weight=1) = 0;

    vector<int> BFS(int initVertex) {
      vector<int> bfs;
      vector<bool> visited(noOfVertices+1);
      queue<int> q;

      q.push(initVertex);
      visited[initVertex] = true;

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        bfs.push_back(u);

        for (int v=1; v<=noOfVertices; v++) {
          if (adjMat[u][v] == 1 && !visited[v]) {
            visited[v] = true;
            q.push(v);
          }
        }
      }

      return bfs;
    }

    vector<int> DFS(int initVertex) {
      vector<int> dfs;
      vector<bool> visited(noOfVertices+1);
      stack<int> s;

      s.push(initVertex);

      while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
          dfs.push_back(u);
          visited[u] = true;

          for (int v=noOfVertices; v>0; v--) {
            if (adjMat[u][v] == 1 && !visited[v]) {
              s.push(v);
            }
          }
        }
      }

      return dfs;
    }
};

class UndirectedGraph: public Graph {
  public:
    UndirectedGraph(int vertices): Graph(vertices) {};

    void addEdge(int v1, int v2, int weight=1) {
      if (v1 <= noOfVertices && v2 <= noOfVertices) {
        adjMat[v1][v2] = weight;
        adjMat[v2][v1] = weight;
      }
    }
};

class DirectedGraph: public Graph {
  public:
    DirectedGraph(int vertices): Graph(vertices) {};

    void addEdge(int v1, int v2, int weight=1) {
      if (v1 <= noOfVertices && v2 <= noOfVertices) {
        adjMat[v1][v2] = weight;
      }
    }
};

int main() {
  UndirectedGraph g(7);

  g.addEdge(1, 3);
  g.addEdge(1, 5);
  g.addEdge(3, 2);
  g.addEdge(3, 4);
  g.addEdge(3, 6);
  g.addEdge(4, 6);
  g.addEdge(4, 7);

  vector<int> dfs = g.DFS(3);
  for (int i=0; i<7; i++)
    cout << dfs[i] << " ";

  return 0;
}
