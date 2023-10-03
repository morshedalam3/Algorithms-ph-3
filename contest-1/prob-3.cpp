#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        priority_queue<int> pq;

        int freq = 0;
        for (char c : S) {
            if (c == '1') {
                freq++;
            } else if (freq > 0) {
                pq.push(freq);
                freq = 0;
            }
        }

        if (freq > 0) {
            pq.push(freq);
        }

        int zazaDrank = 0;
        bool zazaTurn = true;

        while (!pq.empty()) {
            int bottles = pq.top();
            pq.pop();

            if (zazaTurn) {
                zazaDrank += bottles;
            }

            zazaTurn = !zazaTurn;
        }

        cout << zazaDrank << endl;
    }

    return 0;
}
