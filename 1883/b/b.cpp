#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    unordered_map<char, int> count;
    for (int i = 0; i < n; i++) {
        count[s[i]]++;
    }

    bool odd = ((n - k) % 2) == 0;
    for (auto [_, c]: count) {
        if (c % 2 == 0) continue;

        if (!odd) {
            odd = true;
        } else if (k > 0) {
            k--;
        } else {
            cout << "NO\n";
            return;
        }
    }

    if (odd != (k % 2 == 0)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

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