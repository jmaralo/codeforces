#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int x, y, k;
    cin >> x >> y >> k;

    if (y <= x + k) {
        cout << max(x, y) << "\n";
        return;
    }

    cout << (x + k) + ((y - (x + k)) * 2) << "\n";
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