#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<long long> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int l = 0;
    long long mx = LONG_LONG_MIN;
    while (l < n && c[l] < 0) {
        mx = max(mx, c[l]);
        l++;
    }
    if (l == n) {
        cout << mx << "\n";
        return;
    }

    int r = n - 1;
    while (r >= 0 && c[r] < 0) {
        r--;
    }

    long long s1 = 0, s2 = 0;
    for (int i = l; i <= r; i++) {
        if (c[i] < 0) continue;
        if (i % 2)
            s1 += c[i];
        else
            s2 += c[i];
    }

    cout << max(s1, s2) << "\n";
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