#include<bits/stdc++.h>
using namespace std;

int main(){
    string word1, word2;
    
    while (cin >> word1 >> word2) {
        int i = 0; 
        for (char c : word1) {
            if (i < word2.length() && c == word2[i]) {
                i++;
            }
        }
        
        if (i == word2.length()) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}

