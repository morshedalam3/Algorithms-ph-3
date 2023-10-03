#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> H(N);

        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }

        int max1 = 0;
        int max2 = 1;

        for (int i = 1; i < N; i++) {
            if (H[i] > H[max1]) {
                max2 = max1;
                max1 = i;
            } else if (H[i] > H[max2]) {
                max2 = i;
            }
        }

        cout << min(max1, max2) << " " << max(max1, max2) << endl;
    }

    return 0;
}
