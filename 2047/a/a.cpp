#include <bits/stdc++.h>

using namespace std;

void solve(size_t t) {
    size_t n;
    cin >> n;

    size_t happy{0};
    size_t inc{0};
    size_t exact_required{1};

    size_t a;
    size_t current{0};
    for (size_t i{0}; i < n; ++i) {
        cin >> a;

        current += a;
        while (current > exact_required) {
            inc += 8;
            exact_required += inc;
        }
        if (current == exact_required) {
            ++happy;
        }
    }

    cout << happy << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t t{0}; t < tt; ++t) {
        solve(t);
    }
    return 0;
}