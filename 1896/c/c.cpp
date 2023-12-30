#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    size_t n, x;
    cin >> n >> x;

    vector<pair<unsigned int, size_t>> a(n);
    unsigned int ai;
    for (size_t i = 0; i < n; i++) {
        cin >> ai;
        a[i] = {ai, i};
    }
    sort(a.begin(), a.end());
    
    vector<unsigned int> b(n);
    for (size_t i = 0; i < n; i++) cin >> b[i];
    sort(b.begin(), b.end());

    vector<unsigned int> c(n);
    for (size_t i = 0; i < n - x; i++) {
        c[i] = b[x + i];
    }
    for (size_t i = 0; i < x; i++) {
        c[n - x + i] = b[i];
    }

    size_t count = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i].first > c[i]) count++;

    if (count != x) {
        cout << "NO\n";
    } else {
        vector<unsigned int> d(n);
        for (size_t i = 0; i < n; i++) {
            d[a[i].second] = c[i];
        }

        cout << "YES\n";
        for (size_t i = 0; i < n; i++) {
            cout << d[i] << " ";
        }
        cout << "\n";
    }

}

#define TESTCASES true
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