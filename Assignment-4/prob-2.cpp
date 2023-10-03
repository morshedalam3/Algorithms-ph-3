#include <bits/stdc++.h>
using namespace std;

bool canReach(int i, int n, bool dp[]) {
    if (i == n) {
        return true;
    }
    if (i > n || dp[i]) {
        return false;
    }

    dp[i] = true;

    return canReach(i + 3, n, dp) || canReach(i * 2, n, dp);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        bool dp[n+1];
         for (int i = 0; i <n+1; i++) {
        dp[i] = false;
       }

        if (canReach(1, n, dp)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
