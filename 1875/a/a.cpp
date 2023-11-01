#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    long long a, b, n;
    cin >> a >> b >> n;

    long long sum = b;
    for (int i = 0; i < n; ++i) {
        long long t;
        cin >> t;
        sum += min(a - 1, t);
    }

    cout << sum << "\n";
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