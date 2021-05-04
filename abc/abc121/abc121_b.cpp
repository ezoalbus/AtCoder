#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    vector<vector<int>> A;

    // 2次元の入力, vector
    for (int i = 0; i < M; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) {
        vector<int> TEMP(M);
        for (int j = 0; j < M; ++j) {
            cin >> TEMP[j];  // iと間違わないように
        }
        A.push_back(TEMP);
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < M; ++j) {
            sum += A[i][j] * B[j];
        }
        sum += C;
        if (sum > 0) count++;
    }
    cout << count << endl;
}
