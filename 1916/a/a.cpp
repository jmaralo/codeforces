#include <bits/stdc++.h>

using namespace std;

void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<long> b(n);
    long prod = 1;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        prod *= b[i];
    }

    if (2023 % prod == 0) {
        cout << "YES\n";
        cout << 2023 / prod << " ";
        for (int i = 1; i < k; i++) {
            cout << "1 ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
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