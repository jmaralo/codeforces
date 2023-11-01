#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<bool>> valid(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(a[i] - b[j]) <= k) valid[i][j] = true;
        }
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