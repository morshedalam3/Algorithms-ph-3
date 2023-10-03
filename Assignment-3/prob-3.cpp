#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;
    Edge(int a,int b,int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

const int N = 1e5+5;
int parent[N];
int parentSize[N];

void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        if (parentSize[leaderA] > parentSize[leaderB]) {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        } else {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    dsu_set(n);
    long long ans = 0;
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    for (Edge val : v) {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;
        ans += w;
        dsu_union(a, b);
    }

    set<int> parent_set;
    for (int i = 1; i <= n; i++) {
        parent_set.insert(dsu_find(i));
    }

    if (parent_set.size() == 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}