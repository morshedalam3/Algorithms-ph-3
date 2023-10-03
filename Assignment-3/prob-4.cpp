#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int INF = INT_MAX;

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    int s;
    cin >> s;

    int t;
    cin >> t;

    int dis[n+1];
   for (int i = 1; i <=n; i++)
   {
      dis[i]=INT_MAX;
   }
    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dis[u] != INF && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }

    bool isNegCycle = false;
    for (Edge edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (dis[u] != INF && dis[u] + w < dis[v]) {
            isNegCycle = true;
            break;
        }
    }
  if(isNegCycle)
  {
      cout << "Negative Cycle Detected" << endl;
  }else{
     while (t--) {
        int d;
        cin >> d;
        if (dis[d] == INF) {
            cout << "Not Possible" << endl;
        } else {
            cout << dis[d] << endl;
        }
    } 
  }
    

    return 0;
}
