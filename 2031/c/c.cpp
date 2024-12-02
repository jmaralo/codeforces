#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    size_t n;
    cin >> n;

    if (n % 2 == 1) {
        constexpr size_t a{9}, c{25};
        if (n <= c) {
            cout << "-1\n";
            return;
        }

        size_t fill = 3;
        bool used_once = false;
        for (size_t i{0}; i < n; ++i) {
            if ((i == 0) || (i == a) || (i == c)) {
                cout << "1 ";
            } else if ((i == (c + 1)) || (i == (c - 3))) {
                cout << "2 ";
            } else {
                if (used_once) {
                    cout << fill++ << " ";
                    used_once = false;
                } else {
                    cout << fill << " ";
                    used_once = true;
                }
            }
        }

        cout << "\n";
        return;
    }

    for (size_t i{0}; i * 2 < n; ++i) {
        cout << i + 1 << " " << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t i{0}; i < tt; ++i) {
        solve(i);
    }

    return 0;
}