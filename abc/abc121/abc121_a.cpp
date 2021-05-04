#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    int h, w;
    cin >> H >> W;
    cin >> h >> w;

    int res = H * W;
    res -= h * W + w * H - h * w;
    
    cout << res << endl;
}
