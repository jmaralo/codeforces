#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    string s = "codeforces";
    char c;
    int d = 0;
    for (int i = 0; i < 10; i++) {
        cin >> c;
        if (c != s[i]) d++;
    }

    cout << d << "\n";
}

int main() {
    if (!TESTCASES) {
        solve(0);
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}