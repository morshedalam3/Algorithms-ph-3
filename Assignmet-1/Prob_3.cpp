#include<bits/stdc++.h>
using namespace std;

pair<int, int> binarySearchRange( vector<int>& arr,int n, int k) {
    int l = 0;
    int r = n - 1;

    int firstOccur= 1;
    int lastOccur = 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == k) {
            firstOccur = mid;
            lastOccur = mid;

            int left = mid - 1;
            while (left >= 0 && arr[left] == k) {
                firstOccur = left;
                left--;
            }

            int right = mid + 1;
            while (right < arr.size() && arr[right] == k) {
                lastOccur = right;
                right++;
            }

            break;
        } else if (arr[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return make_pair(firstOccur, lastOccur);
}

int main() {
    int N, k;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cin >> k;

    pair<int, int> indices = binarySearchRange(arr,N,k);
    if (indices.first != indices.second) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
