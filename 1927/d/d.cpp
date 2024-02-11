#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void solve(int tt) {
    size_t n;
    cin >> n;

    vector<uint> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<size_t> first_equal(n);
    first_equal[0] = 0;
    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[first_equal[i - 1]]) {
            first_equal[i] = first_equal[i - 1];
        } else {
            first_equal[i] = i;
        }
    }

    size_t q;
    cin >> q;

    size_t l, r;
    for (size_t i = 0; i < q; i++) {
        cin >> l >> r;
        l--;
        r--;

        if (first_equal[l] == first_equal[r]) {
            cout << "-1 -1\n";
            continue;
        }

        auto different = upper_bound(first_equal.begin(), first_equal.end(), first_equal[l]);
        size_t position = different - first_equal.begin();

        cout << l + 1 << " " << position + 1 << "\n";
    }
    cout << "\n";
}

#define TESTCASES true
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES) {
        solve(0);
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}