#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    long long n;
    cin >> n;

    long long ones{0};

    short a;
    for (long long i{0}; i < (n + n); ++i) {
        cin >> a;
        if (a != 0) ++ones;
    }

    cout << (ones % 2) << " " << min(ones, (n + n - ones)) << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t i{0}; i < tt; ++i) solve(i);

    return 0;
}