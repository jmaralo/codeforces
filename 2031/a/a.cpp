#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    size_t n;
    cin >> n;

    size_t h[n];
    unordered_map<size_t, size_t> h_count;
    for (size_t i{0}; i < n; ++i) {
        cin >> h[i];
        ++h_count[h[i]];
    }

    size_t max_count{0};
    for (const auto &[_, count] : h_count) {
        max_count = max(max_count, count);
    }

    cout << n - max_count << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t i{0}; i < tt; ++i) {
        solve(i);
    }

    return 0;
}