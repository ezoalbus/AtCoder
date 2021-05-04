#include <bits/stdc++.h>
using namespace std;

/*
## 解法メモ
- エナジードリンクが安い店から順番に、できるだけ多くのエナジードリンクを買うのが最適解
- エナジードリンクが安い順に、お店をソートする
    - 価格だけをソートすると、その店で買える最大本数が分からなくなってしまうので、pair(first=価格，second=最大本数) の vectorを考え，価格(first)が安い順にソートする（辞書式）
*/

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    vector<pair<long long, long long>> shop(N);
    for (int i = 0; i < N; ++i) {
        shop[i].first = A[i];
        shop[i].second = B[i];
    }
    sort(shop.begin(), shop.end());  // 辞書式ソートになる
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        if (M == 0) break;
        // 買える数 > M の場合は，Mだけ買えばよい
        long long buy_n = min(shop[i].second, (long long)M);  
        sum += shop[i].first * buy_n;

        // Mを減らしていく
        M -= buy_n;
    }

    cout << sum << endl;

}
