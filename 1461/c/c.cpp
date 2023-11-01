#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> r(m);
    vector<double> p(m);
    for (int i = 0; i < m; i++) cin >> r[i] >> p[i];


    int sut = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == i + 1) sut--;
        else break;
    }

    if (sut == 0) {
        cout << 1.0 << "\n";
        return;
    }

    vector<double> pf;
    for (int i = 0; i < m; i++) {
        if (r[i] >= sut) {
            pf.push_back(p[i]);
        }
    }

    if (pf.size() == 0) {
        cout << 0.0 << "\n";
        return;
    }
    sort(pf.begin(), pf.end());

    double prob = pf[pf.size() - 1];

    for (int i = pf.size() - 2; i >= 0; i--) {
        prob = pf[i] + ((1 - pf[i]) * prob);
    }

    cout << prob << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(6);

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