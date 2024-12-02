#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    size_t n, k;
    cin >> n >> k;

    if (k == 1 || k == n) {
        if (k == 1 && n == 1)
            cout << "1\n1\n";
        else
            cout << "-1\n";
        return;
    }

    if (k % 2 == 0) {
        cout << "3\n1 " << k << " " << (k + 1) << "\n";
    } else {
        cout << "5\n1 2 " << k << " " << (k + 1) << " " << n << "\n";
    }
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t i{0}; i < tt; ++i) solve(i);

    return 0;
}