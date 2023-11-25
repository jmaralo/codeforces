#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    size_t n;
    cin >> n;

    vector<unsigned int> c(n);
    for (size_t i = 0; i < n; i++) cin >> c[i];

    unsigned int p = 1;
    unsigned long long ans = 0;
    for (size_t i = 0; i < n; i++) {
        if (c[i] > p) ans += c[i] - p;
        p = c[i];
    }

    cout << ans << "\n";
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