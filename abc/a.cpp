#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int res = 0;
    string subStr = "ZONe";
    int subStrSize = subStr.size();
    int pos = S.find(subStr);

    while (pos != string::npos) {
       res++;
       pos = S.find(subStr, pos + subStrSize); 
    }

    cout << res << endl;
}