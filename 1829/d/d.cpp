#include <bits/stdc++.h>

using namespace std;

bool rec(int n, int target) {
    if (n == target) return true;

    if (n < target) return false;

    if (n % 3 != 0) return false;

    return rec(n / 3, target) || rec(2 * (n / 3), target);
}

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;
    if (rec(n, m)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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