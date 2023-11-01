#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    long long n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, long long> pf;
    for (int i = 0; i < n; i++) {
        while(a[i] % 2 == 0) {
            pf[2]++;
            a[i] /= 2;
        }

        for (int j = 3; j <= sqrt(a[i]); j += 2) {
            while (a[i] % j == 0) {
                pf[j]++;
                a[i] /= j;
            }
        }

        if (a[i] > 2) pf[a[i]]++;
    }

    for (auto [f, c]: pf) {
        if (c % n != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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