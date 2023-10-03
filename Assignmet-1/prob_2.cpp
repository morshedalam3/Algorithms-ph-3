#include<bits/stdc++.h>
using namespace std;

int binarySearch( vector<int>& arr,int n, int k) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == k) {
            return mid; 
        } else if (arr[mid] < k) {
            l = mid + 1; 
        } else {
            r = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int N, k;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cin >> k;

    int index = binarySearch(arr,N, k);

    if (index != -1) {
        cout << index << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
