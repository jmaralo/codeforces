#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> x(q);
    for(int i = 0; i < q; i++) cin >> x[i];

    int mask = 0;
    int mn = INT_MAX;
    for (int i = 0; i < q; i++) {
        if (x[i] < mn) {
            mn = x[i];
            mask |= (1 << (x[i] - 1));
        }
    }

    for (int i = 0; i < n; i++) {
        int a_i = a[i], j = 0;
        while((a_i & 1) == 0) {
            a_i >>= 1;
            j++;
        }
        a[i] |= (mask & ((1 << j) - 1));
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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