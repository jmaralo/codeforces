#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    pair<int, int> a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

    int res = 1;
    if (a.first < b.first && a.first < c.first) {
        res += min(b.first, c.first) - a.first;
    } else if (a.first > b.first && a.first > c.first) {
        res += a.first - max(b.first, c.first);
    }

    if (a.second < b.second && a.second < c.second) {
        res += min(b.second, c.second) - a.second;
    } else if (a.second > b.second && a.second > c.second) {
        res += a.second - max(b.second, c.second);
    }

    cout << res << "\n";
}

int main() {
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