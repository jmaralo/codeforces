#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    
    int l = 0, r = 0;
    while (r < x) {
        sum -= a[r] + a[r];
        r++;
    }
    
    int mx = sum;
    while (l < k) {
        sum += a[l];
        if (r < n) {
            sum -= a[r] + a[r];
            r++;
        }
        l++;
        mx = max(mx, sum);
    }

    cout << mx << "\n";
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