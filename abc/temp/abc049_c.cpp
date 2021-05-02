#include <bits/stdc++.h>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());  // 反転(破壊的)
    
    for (int i = 0; i < 4; ++i) {
        reverse(divide[i].begin(),divide[i].end());
    }

    bool can = true;
    // Sの文字を最初(最後)から1文字ずつ操作していく(外側のループ)
    for (int i = 0; i < S.size();) {
        can = false;
        for (int j = 0; j < 4; ++j) {
            string d = divide[j];
            if (S.substr(i, d.size()) == d) {
                can = true;
                i += d.size();
            }
        }
        // どのdivideもダメだった場合
        if (!can) break;
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}
