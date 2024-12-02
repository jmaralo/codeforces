#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int x{0}, y{0};
    for (int j{0}; j <= 100; ++j) {
        for (int i{0}; i < n; ++i) {
            switch (s[i]) {
                case 'N':
                    y += 1;
                    break;
                case 'E':
                    x += 1;
                    break;
                case 'W':
                    x -= 1;
                    break;
                case 'S':
                    y -= 1;
                    break;
            }

            if (x == a && y == b) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t t{0}; t < tt; ++t) solve(t);

    return 0;
}