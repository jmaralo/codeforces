#include <bits/stdc++.h>

using namespace std;

void solve(int tt) {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> w(n + 1, 0), ans(n - 1, 0);
    int j = 1;
    for (int i = 2; i <= n; i++) {
        if (w[j] == x || w[j] == y) {
            j = i;
        }
        w[j]++;
        ans[i - 2] = j;
    }

    for (int i = 0; i < n + 1; i++) {
        if (w[i] != x && w[i] != y) {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}