#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int swaps = 0;
    for (int i = 0; i < n; i++) {
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