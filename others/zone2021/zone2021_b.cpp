#include <bits/stdc++.h>
using namespace std;

int main() {
    float N, D, H;
    cin >> N >> D >> H;
    float d[1010];
    float h[1010];

    for (int i = 0; i < N; ++i) cin >> d[i] >> h[i];

    float res = 0;
    float temp = 0;
    for (int i = 0; i < N; ++i) {
        temp = H - D * (H - h[i]) / (D - d[i]);
        if (res < temp) {
            res = temp;
        }
    }
    cout << max(0.f, res) << endl;
}