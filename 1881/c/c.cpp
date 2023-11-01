#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    int res = 0;
    for (int i = 0; i < (n / 2); i++) {
        for (int j = i; j < (n - i - 1); j++) {
            int ai = i, bi = n - j - 1, ci = n - i - 1, di = j;
            int aj = j, bj = i, cj = n - j - 1, dj = n - i - 1;

            int mx = max(max(a[ai][aj], a[bi][bj]), max(a[ci][cj], a[di][dj]));

            res += mx - a[ai][aj];
            res += mx - a[bi][bj];
            res += mx - a[ci][cj];
            res += mx - a[di][dj];
        }
    }

    cout << res << "\n";
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