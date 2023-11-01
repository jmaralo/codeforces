#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int j = 0, c = 1, r = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] / a[i] < 2) c++;
        else {
            r += c > k ? c - k : 0;
            j = i;
            c = 1;
        }
    }
    r += c > k ? c - k : 0;

    cout << r << "\n";
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