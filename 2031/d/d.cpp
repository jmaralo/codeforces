#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &t) {
    size_t n;
    cin >> n;

    vector<size_t> a(n);
    // height, position
    vector<pair<size_t, size_t>> shortest(n);
    vector<pair<size_t, size_t>> tallest(n);

    for (size_t i{0}; i < n; ++i) {
        cin >> a[i];
        if (i != 0) {
            tallest[i] = tallest[i - 1].first <= a[i] ? make_pair(a[i], i)
                                                      : tallest[i - 1];
        } else {
            tallest[i] = {a[i], i};
        }
    }

    shortest[n - 1] = {a[n - 1], n - 1};
    for (size_t i{n - 1}; i > 0; --i) {
        shortest[i - 1] = shortest[i].first >= a[i - 1]
                              ? make_pair(a[i - 1], i - 1)
                              : shortest[i];
    }

    for (size_t i{0}; i < n; ++i) {
        size_t small{i}, tall{i};
        while (small != shortest[tall].second ||
               tall != tallest[small].second) {
            small = shortest[tall].second;
            tall = tallest[small].second;
        }
        cout << tallest[small].first << " ";
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