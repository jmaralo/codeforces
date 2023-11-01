#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, m, k;
    cin >> n >> m >> k;

    int d = max(0, (m / n) - 1);

    if (k == 1) {
        cout << "1\n";
    } else if (n == 1) {
        cout << m << "\n";
    } else if (k == 2) {
        cout << min(n, m) + d << "\n";
    } else if (k == 3) {
        cout << max(m - n - d, 0) << "\n";
    } else {
        cout << "0\n";
    }
}

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