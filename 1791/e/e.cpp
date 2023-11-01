#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    long long minus = 0, sum = 0, mn = INT_MAX, a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) {
            minus++;
            a = -a;
        }
        mn = min(mn, a);
        sum += a;
    }

    if (minus % 2) {
        cout << sum - mn - mn << "\n";
    } else {
        cout << sum << "\n";
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