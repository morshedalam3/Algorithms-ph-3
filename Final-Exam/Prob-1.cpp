#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

int unbounded_knapsack(int n, int s, int val[], int w[]) {
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s) {
        int ch1 = val[n - 1] + unbounded_knapsack(n, s - w[n - 1], val, w);
        int ch2 = unbounded_knapsack(n - 1, s, val, w);
        return dp[n][s] = max(ch1, ch2);
    } else {
        return dp[n][s] = unbounded_knapsack(n - 1, s, val, w);
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    while (T--) {
        int n, m;
        cin >> n >> m;

        if (m > 1000) {
            cout << "NO" << endl;
            continue;
        }

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (unbounded_knapsack(n, 1000 - m, a, a) == 1000 - m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
