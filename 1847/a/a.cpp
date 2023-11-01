#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> df(n, 0);
    for (int i = 0; i < n - 1; i++) {
        df[i] = abs(a[i] - a[i + 1]);
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) pq.push({df[i], i});

    for (int i = 0; i < k - 1; i++) {
        pair<int, int> curr = pq.top();
        pq.pop();
        df[curr.second] = 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += df[i];
    }

    cout << sum << "\n";
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