#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    int mx = 0, v;
    bool found = false;
    for (int i = 0; i < n; i++) {
        cin >> v;
        if (!found && v < 0) {
            cout << v << "\n";
            found = true;
        }
        mx = max(mx, v);
    }

    if (!found)
        cout << mx << "\n";
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