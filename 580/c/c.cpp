#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> g(n, vector<int>(0));
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    g[0].push_back(-1);

    int total = 0;
    queue<tuple<int, int, int>> dfs;
    dfs.push({0, 0, -1});
    while (!dfs.empty()) {
        tuple<int, int, int> d = dfs.front();
        dfs.pop();
        int curr = get<0>(d), cats = get<1>(d), parent = get<2>(d);
        if (g[curr].size() == 1) {
            total += (cats + a[curr] <= m);
            continue;
        }

        for (int i = 0; i < g[curr].size(); i++) {
            if (g[curr][i] == parent) continue;
            if (!a[curr]) {
                dfs.push({g[curr][i], 0, curr});
            } else if (cats >= m) {
                continue;
            } else {
                dfs.push({g[curr][i], cats + 1, curr});
            }
        }
    }

    cout << total << "\n";
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