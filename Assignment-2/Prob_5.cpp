// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1000;
// vector<int> adj[N];
// bool visited[N];

// int dfs(int u) {
//     visited[u] = true;
//     int count = 1;

//     for (int v : adj[u]) {
//         if (!visited[v]) {
//             count += dfs(v);
//         }
//     }

//     return count;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u); 
//     }

//     vector<int> cmpV;

//     for (int i = 1; i <= n; ++i) {
//         if (!visited[i]) {
//             int cmpSize = dfs(i);
//             if (cmpSize > 1) {
//                 cmpV.push_back(cmpSize);
//             }
//         }
//     }

//     sort(cmpV.begin(), cmpV.end());

//     for (int size : cmpV) {
//         cout << size << " ";
//     }
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> adj[N];
bool visited[N];

int bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    int count = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        count++;

        for (int v : adj[current]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
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
        adj[v].push_back(u);
    }

    vector<int> cmpV;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            int cmpSize = bfs(i);
            if (cmpSize > 1) {
                cmpV.push_back(cmpSize);
            }
        }
    }

    sort(cmpV.begin(), cmpV.end());

    for (int size : cmpV) {
        cout << size << " ";
    }
    
    return 0;
}
