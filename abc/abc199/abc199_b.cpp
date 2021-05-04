#include <iostream>

using namespace std;

int N;
int A[1010];
int B[1010];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    int max_A = A[0]; 
    int min_B = B[0]; 
    for (int i = 0; i < N; ++i) {
        if (A[i] > max_A) {
            max_A = A[i];
        }
        if (B[i] < min_B) {
            min_B = B[i];
        }
    }

    cout << max(0, min_B - max_A + 1) << endl;
}