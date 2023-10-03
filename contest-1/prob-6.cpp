#include <bits/stdc++.h>
using namespace std;

const int N = 105;

vector<int> v[N];
bool vis[N][N]; 
int n;

bool dfs(int src, int dest, int K) {
    if (K < 0) return false;
    if (src == dest) return true;
    if (vis[src][K]) return false;

    vis[src][K] = true;

    for (int neighbor : v[src]) {
        if (dfs(neighbor, dest, K - 1)) return true;
    }

    return false;
}

int main() {
    int e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int X, Y, K;
    cin >> X >> Y >> K;

    if (dfs(X, Y, K*2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
