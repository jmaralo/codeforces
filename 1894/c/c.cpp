#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int i = n - 1;
    vector<bool> visited(n, false);
    for (int j = 0; j < k; j++) {
        if (visited[i]) {
            cout << "Yes\n";
            return;
        }
        visited[i] = true;
        if (a[i] > n) {
            cout << "No\n";
            return;
        }
        i -= a[i];
        if (i < 0) {
            i = n + i;
        }
    }

    cout << "Yes\n";
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