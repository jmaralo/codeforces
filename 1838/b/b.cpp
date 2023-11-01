#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    int op = 0, tp = 0, v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        if (v == 1)
            op = i;
        else if (v == 2)
            tp = i;
    }
    if (op >= n / 2) {
        cout << "1 " << tp + 1 << "\n";
    } else {
        cout << tp + 1 << " " << n << "\n";
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