#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    deque<char> T;

    bool reversed_f = 0;

    for(int i = 0; i < S.size(); ++i) {
        if (S[i] == 'R') {
            reversed_f ^= 1;  // 反転
            continue;
        }
        if (T.size() == 0) {
            T.push_back(S[i]);
            continue;
        }
        if (reversed_f) {
            if (T[0] == S[i]) T.pop_front();
            else T.push_front(S[i]); 
        }
        else {
            if (T.back() == S[i]) T.pop_back();
            else T.push_back(S[i]); 
        }
    }

    if (reversed_f) reverse(T.begin(),T.end());

    if (T.size() == 0) cout << "" << endl;
    else {
    for(int i = 0; i < T.size(); ++i) {
        cout << T[i];
    }
    cout << endl;
    }
}