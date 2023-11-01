#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;
    if (k == n - 1) {
        if (n < 5) {
            cout << "-1\n";
            return;
        }

        cout << "0 " << n - 4 << "\n";
        cout << "1 3\n";
        cout << "2 " << n - 3 << "\n";

        for (int i = 4; i < n / 2; i++) {
            cout << i << " " << n - i - 1 << "\n";
        }

        cout << n - 2 << " " << n - 1 << "\n";
        return;
    }

    cout << "0 " << n - k - 1 << "\n";
    if (k != 0) cout << k << " " << n - 1 << "\n";

    int skip = k < n / 2 ? k : n - k - 1;
    for (int i = 1; i < n / 2; i++) {
        if (i == skip) continue;
        cout << i << " " << n - i - 1 << "\n";
    }
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