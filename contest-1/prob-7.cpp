#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(int N, int D, vector<int>& A) {
    int max_sum = 0;
    for (int num : A) {
        max_sum += num;
    }

    vector<vector<int>> dp(N + 1, vector<int>(max_sum + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= max_sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - A[i - 1] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - A[i - 1]]) % MOD;
            }
        }
    }

   long long int ways = dp[N][max_sum];
    if (D > max_sum || (max_sum - D) % 2 != 0) {
        return 0;
    }

    int target_sum = (max_sum - D) / 2;
    ways = ways * dp[N][target_sum] %MOD;

    return ways;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, D;
        cin >> N >> D;
        vector<int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int ans = countWays(N, D, A);
        cout << ans << endl;
    }

    return 0;
}
