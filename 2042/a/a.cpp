#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &test) {
    size_t n;
    int k;
    cin >> n >> k;

    vector<int> a(n);
    for (size_t i{0}; i < n; ++i) cin >> a[i];
    sort(a.rbegin(), a.rend());

    size_t overflows_at{0};
    int sum{0};
    for (; sum < k && overflows_at < n; ++overflows_at) {
        sum += a[overflows_at];
    }

    if (sum == k) {
        cout << "0\n";
        return;
    }

    if (sum > k) {
        sum -= a[--overflows_at];
    }

    cout << k - sum << "\n";
}

int main() {
    size_t testcases;
    cin >> testcases;

    for (size_t test{0}; test < testcases; ++test) {
        solve(test);
    }

    return 0;
}