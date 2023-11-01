#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<pair<long long, int>> comb(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            comb[(i * m) + j] = {a[i] * b[j], i};
        }
    }

    sort(comb.rbegin(), comb.rend());

    int i = 1;
    while (i < comb.size() && comb[i].second == comb[0].second)
        i++;

    if (i == comb.size())
        i--;
    cout << comb[i].first << "\n";
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