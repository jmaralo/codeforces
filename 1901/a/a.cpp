#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    size_t n;
    unsigned int x;
    cin >> n >> x;

    vector<unsigned int> a(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];

    unsigned int c = 0, ans = 0;
    for (size_t i = 0; i < n; i++) {
        ans = max(ans, a[i] - c);
        c = a[i];
    }
    ans = max(ans, 2 * (x - c));

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