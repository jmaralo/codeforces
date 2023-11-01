#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    int mx = 0, curr = 0;
    bool bit;
    for (int i = 0; i < n; i++) {
        cin >> bit;
        if (bit) {
            mx = max(mx, curr);
            curr = 0;
        } else {
            curr++;
        }
    }
    mx = max(mx, curr);

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