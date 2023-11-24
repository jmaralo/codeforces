#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void solve(int tt) {
    size_t n;
    cin >> n;

    uint k;
    cin >> k;

    string s;
    cin >> s;

    uint cb = 0;
    for (size_t i = 0; i < n; i++) {
        if (s[i] == 'B') cb++;
    }

    if (cb == k) {
        cout << "0\n";
        return;
    } else if (cb < k) {
        cout << "1\n";
        uint ca = 0;
        for (size_t i = 0; i < n; i++) {
            if (s[i] == 'A') ca++;
            if (ca == (k - cb)) {
                cout << (i + 1) << " B\n";
                return;
            }
        }
        cout << n << " B\n";
    } else {
        cout << "1\n";
        uint cb2 = 0;
        for (size_t i = 0; i < n; i++) {
            if (s[i] == 'B') cb2++;
            if (cb2 == (cb - k)) {
                cout << (i + 1) << " A\n";
                return;
            }
        }
        cout << n << " A\n";
    }
}

#define TESTCASES true
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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