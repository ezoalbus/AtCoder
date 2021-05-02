#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int t[110000], x[110000], y[110000];
    t[0] = x[0] = y[0] = 0;
    for(int i = 1; i < N + 1; ++i) {
        cin >> t[i] >> x[i] >> y[i];
    }

    bool flag = true;
    int diff;

    for (int i = 0; i < N; ++i) {
        diff = abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
        int diff2 = diff - t[i + 1] + t[i];
        if (diff2 > 0) flag = false;
        if (diff2 % 2 != 0) flag = false;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
