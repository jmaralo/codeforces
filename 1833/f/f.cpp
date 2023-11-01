#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    vector<pair<int, int>> c(count.begin(), count.end());

    int i = 0;
    int curr = 0, combs = 1;
    for (; i < c.size() && curr < m; i++) {
        curr += c[i].second;
        combs *= c[i].second;
    }

    if (curr < m) {
        cout << "0\n";
    }

    int tot = combs;
    for (; i < c.size(); i++) {
    }
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