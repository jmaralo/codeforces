#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {a[i], b[i]};
    }
    sort(p.begin(), p.end());
    int m = 0;

    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (p[i].first * p[j].first == p[i].second + p[j].second) c++;
        }

    cout << c << "\n";
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