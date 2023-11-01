#include <bits/stdc++.h>

using namespace std;

int rec(vector<int>& a, int i, int k, int d) {
    if (i >= a.size()) return 0;

    return max(a[i] - k + rec(a, i + 1, k, d), (a[i] / d) + rec(a, i + 1, k, d * 2));
}

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << rec(a, 0, k, 2) << "\n";
}

int main() {
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