#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k == 4) {
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, (4 - (a[i] % 4)) % 4); 
        }

        int mn1 = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++) {
            int b = (2 - (a[i] % 2)) % 2;
            if (b < mn1) {
                mn1 = b;
                idx = i;
            }
        }

        int mn2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            mn2 = min(mn2, (2 - (a[i] % 2)) % 2); 
        }

        cout << min(mn, mn1 + mn2) << "\n";
        return;
    }

    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        mn = min(mn, (k - (a[i] % k)) % k); 
    }

    cout << mn << "\n";
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