#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;
    n *= 2;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int l = 0;
    for (int i = 1; i < (n / 2); i++) {
        l += (a[i] - a[i - 1]) + (a[n - i] - a[n - i - 1]);
    }

    cout << l << "\n";
    for (int i = 0; i < (n / 2); i++) {
        cout << a[i] << " " << a[n - i - 1] << "\n";
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