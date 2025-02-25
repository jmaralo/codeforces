#include <bits/stdc++.h>

using namespace std;

void solve(size_t t) {
    size_t n;
    cin >> n;

    vector<long long> a(n);
    for (size_t i{0}; i < n; ++i) cin >> a[i];

    vector<long long> b(n);
    for (size_t i{0}; i < n; ++i) cin >> b[i];

    long long best_sum{0};
    long long best_skipped{LONG_LONG_MIN};
    for (size_t i{0}; i < n; ++i) {
        if (a[i] > b[i]) {
            best_sum += a[i];
            best_skipped = max(best_skipped, b[i]);
        } else {
            best_sum += b[i];
            best_skipped = max(best_skipped, a[i]);
        }
    }

    cout << best_sum + best_skipped << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t t{0}; t < tt; ++t) {
        solve(t);
    }

    return 0;
}