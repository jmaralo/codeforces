#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    long long a, m;
    cin >> a >> m;

    vector<bool> f(m, false);
    for (long long i = 0; i < m; i++) {
        if (f[a % m]) {
            cout << "No\n";
            return;
        } else if (a % m == 0) {
            cout << "Yes\n";
            return;
        }
        f[a % m] = true;
        a += a % m;
    }

    cout << "No\n";
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