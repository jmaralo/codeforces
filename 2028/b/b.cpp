#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    unsigned long long n, b, c;
    cin >> n >> b >> c;

    if (b == 0) {
        if ((c + 1) >= (n - 1))
            cout << ((c < n) ? (n - 1) : n) << "\n";
        else
            cout << "-1\n";
        return;
    }

    if (c < n)
        cout << n - (((n - c - 1) / b) + 1) << "\n";
    else
        cout << n << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t t{0}; t < tt; ++t) solve(t);

    return 0;
}