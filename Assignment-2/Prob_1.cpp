#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int> adj[N];
int dist[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int v : adj[node]) {
            if (dist[v] == -1) {
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int S, D;
        cin >> S >> D;

        for (int i = 0; i < n; ++i) {
            dist[i] = -1;
        }

        bfs(S);

        if (dist[D] == -1) {
            cout << -1 << endl;
        } else {
            cout << dist[D] << endl;
        }
    }

    return 0;
}
