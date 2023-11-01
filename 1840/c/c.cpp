#include <bits/stdc++.h>

using namespace std;

long long triang(int a) {
    if (a <= 0) return 0;

    long long t = 0;
    for (int i = 1; i <= a; i++)
        t += i;
    return t;
}

#define TESTCASES true
void solve(int tt) {
    int n, k, q;
    cin >> n >> k >> q;

    long long ans = 0;
    int a, curr = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a <= q) {
            curr++;
        } else {
            ans += triang(curr - k + 1);
            curr = 0;
        }
    }
    ans += triang(curr - k + 1);

    cout << ans << "\n";
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