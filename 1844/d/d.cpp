#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    int m;
    for (int i = 1; i < n; i++) {
        if (n % i != 0) {
            m = i;
            break;
        }
    }

    string ans;
    for (int i = 0; i < n; i++) {
        ans += 'a' + (i % m);
    }

    cout << ans << "\n";
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