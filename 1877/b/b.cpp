#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    long long n, p;
    cin >> n >> p;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<long long, long long>> c(n);
    for (int i = 0; i < n; i++) c[i] = {b[i], a[i]};
    sort(c.begin(), c.end());

    int f = 1;
    long long cost = p;
    for (int i = 0; i < n && f < n; i++) {
        for (int j = 0; j < c[i].second && f < n; j++) {
            cost += min(p, c[i].first);
            f++;
        }
    }

    cout << cost << "\n";
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