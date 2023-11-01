#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int a, b, n;
    cin >> a >> b >> n;

    a *= 10;
    for (int i = 0; a % b != 0 && i < 9; i++) a++;
    if (a % b != 0) {
        cout << "-1\n";
        return;
    }

    cout << to_string(a);
    for (int i = 1; i < n; i++) {
        cout << '0';
    }

    cout << "\n";
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