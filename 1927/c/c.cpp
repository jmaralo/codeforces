#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

size_t get_diff_length(set<uint> &a, set<uint> &b) {
    size_t diff_length = 0;

    vector<uint> diff(a.size());
    auto diff_last = set_difference(a.begin(), a.end(), b.begin(), b.end(), diff.begin());
    
    auto diff_iterator = diff.begin();
    while (diff_iterator != diff_last) {
        diff_iterator++;
        diff_length++;
    }

    return diff_length;
}

void solve(int tt) {
    size_t n, m, k;
    cin >> n >> m >> k;

    uint a;
    set<uint> valid_a;
    set<uint> valid_union;
    for (size_t i = 0; i < n; i++) {
        cin >> a;
        if (a <= k) {
            valid_a.insert(a);
            valid_union.insert(a);
        }
    }

    uint b;
    set<uint> valid_b;
    for (size_t i = 0; i < m; i++) {
        cin >> b;
        if (b <= k) {
            valid_b.insert(b);
            valid_union.insert(b);
        }
    }

    if (valid_a.size() < (k / 2) || valid_b.size() < (k / 2) || valid_union.size() != k) {
        cout << "NO\n";
        return;
    }

    size_t ab_diff = get_diff_length(valid_a, valid_b);
    if (ab_diff >= (k / 2)) {
        cout << "YES\n";
        return;
    }
    size_t a_remaining = (k / 2) - ab_diff;
    
    size_t ba_diff = get_diff_length(valid_b, valid_a);
    if (ba_diff >= (k / 2)) {
        cout << "YES\n";
        return;
    }
    size_t b_remaining = (k / 2) - ba_diff;

    if ((ab_diff + a_remaining + ba_diff + b_remaining) == k) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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