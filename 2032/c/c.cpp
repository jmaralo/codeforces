#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    size_t n;
    cin >> n;

    vector<size_t> a(n);
    for (size_t i{0}; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    size_t min_operations{SIZE_MAX};
    auto next_greater{a.begin()};
    for (auto current{a.begin()}; current != a.end(); current = next_greater) {
        next_greater = upper_bound(a.begin(), a.end(), *current);
        if (next_greater == a.end()) break;

        auto last_valid =
            lower_bound(a.begin(), a.end(), *current + *next_greater);

        // size_t foo = static_cast<size_t>(distance(a.begin(), current));
        // size_t bar = static_cast<size_t>(distance(last_valid, a.end()));

        min_operations =
            min(min_operations,
                static_cast<size_t>(distance(a.begin(), current)) +
                    static_cast<size_t>(distance(last_valid, a.end())));
    }
    if (min_operations == SIZE_MAX) min_operations = 0;

    cout << min_operations << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t i{0}; i < tt; ++i) solve(i);

    return 0;
}