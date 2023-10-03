#include<bits/stdc++.h>
using namespace std;

using namespace std;

int minCoinDifference(vector<int>& coins, int N) {
    int sum = 0;
    for (int coin : coins) {
        sum += coin;
    }

    int dp[N + 1][sum + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (coins[i - 1] <= j) {
                dp[i][j] = max(coins[i - 1] + dp[i - 1][j - coins[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int chinkiSum = dp[N][sum / 2];
    int minkiSum = sum - chinkiSum;

    return abs(chinkiSum - minkiSum);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> coins(N);
        for (int i = 0; i < N; i++) {
            cin >> coins[i];
        }

        int minDiff = minCoinDifference(coins, N);
        cout << minDiff << endl;
    }

    return 0;
}


// important sign
// ()
// &&
// !=