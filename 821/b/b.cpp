#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    long long m, b;
    cin >> m >> b;

    long long mx = 0, y;
    for (long long x = 0; x <= m*b; x += m) {
        y = b - (x / m);
        mx = max(mx, ((x * (x + 1) * (y + 1)) + (y * (x + 1) * (y + 1))) / 2);
    }

    cout << mx << "\n";
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