#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector <int> adj[N];
bool visited[N];

int dfs(int u) {
    visited[u] = true;
    int cnt = 0;

    for (int v: adj[u]) {
         if(visited[v] == true) continue;
         cnt ++;
         dfs(v);
    }

    return cnt;
}


int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int K;
    cin >> K;
    for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
    int connected = dfs(K);
    cout << connected << endl;
    return 0;
}
