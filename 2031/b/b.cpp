#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    size_t n;
    cin >> n;

    size_t p[n];
    for (size_t i{0}; i < n; ++i) {
        cin >> p[i];
    }

    for (size_t i{0}; i < n; ++i) {
        if (p[i] == (i + 1)) {
            continue;
        }

        if (i < (n - 1) && (p[i] == (i + 2)) && (p[i + 1] == (i + 1))) {
            swap(p[i], p[i + 1]);
            continue;
        }

        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t i{0}; i < tt; ++i) {
        solve(i);
    }

    return 0;
}