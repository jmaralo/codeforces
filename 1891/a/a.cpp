#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int prev = a[0];
    for (int i = 1; i < n; i++) {
        if (prev > a[i] && ((i) & (i - 1))) {
            cout << "NO\n";
            return;
        }
        prev = a[i];
    }

    cout << "YES\n";
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