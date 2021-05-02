#include <bits/stdc++.h>
using namespace std;

int main() {
    // const vector<int> satsu = {10000, 5000, 1000};
    int n, y;
    cin >> n >> y;
    int res10000 = -1;
    int res5000 = -1;
    int res1000 = -1;

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n - i + 1; ++j) {
            int sum_money = 10000 * i + 5000 * j + 1000 * (n - i - j);
            if (sum_money == y) {
                res10000 = i;
                res5000 = j;
                res1000 = n - i - j;
            }
        }
    }
    
    cout << res10000 << " " << res5000 << " " << res1000 << endl;
}