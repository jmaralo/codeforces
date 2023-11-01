#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int a, b;
    cin >> a >> b;

    if (a == 1) {
        cout << a + b << "\n";
    } else {
        cout << a - 1 << "\n";
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