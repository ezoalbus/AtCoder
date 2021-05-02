#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60; // 十分大きい値を 1 つ決める

int main() {
    // 入力
    int N;
    cin >> N;
    // h: 高さ, s: 上昇速度[/sec]
    long long A[N], B[N], C[N], D[N], E[N];
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];

    // 二分探索
    // P(x)
    long long left = 0, right = INF;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        
        // 判定
        bool ok = true;
        vector<long long> t(N, 0); // 各風船を割るまでの制限時間
        for (int i = 0; i < N; ++i) {
            // そもそも mid が初期高度より低かったらfalse
            if (mid < A[i]) ok = false; 
        }
        // 時間制限がさし迫っている順にソート
        sort(t.begin(), t.end()); 
        for (int i = 0; i < N; ++i) {
            if (t[i] < i) ok = false; // 時間切れ発生
        }

        if (ok) right = mid;
        else left = mid;
    }

    cout << right << endl;
}