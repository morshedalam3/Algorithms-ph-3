#include<bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int> adj[N];
bool visited[N];

int dfs(int u) {
    visited[u] = true;
    int count = 1; 
    
    for (int v : adj[u]) {
        if (visited[v] == true) continue;
            count += dfs(v);
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int K;
    cin >> K;
    int total = dfs(K);
    cout << total-1 << endl;
    
    return 0;
}
