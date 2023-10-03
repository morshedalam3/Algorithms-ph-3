#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << '1' << endl;
    } else {
        for (int i = 1; i <= N; i++) {
            cout << i;
        }
        cout << endl;
        for (int i = 2; i < N; i++) {
            cout << i;
            for (int j = 2; j < N; j++) {
                cout << " ";
            }
            cout << N << endl;
        }
        for (int i = 1; i <= N; i++) {
            cout << N;
        }
        cout << endl;
    }

    return 0;
}