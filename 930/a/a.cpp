#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> d(n, 0);
    vector<vector<int>> g(n, vector<int>(0));
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        g[v - 1].push_back(i);
    }

    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    while (!bfs.empty()) {
        pair<int, int> curr = bfs.front();
        bfs.pop();
        d[curr.second]++;
        for (int i = 0; i < g[curr.first].size(); i++) {
            bfs.push({g[curr.first][i], curr.second + 1});
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += d[i] % 2;
    }

    cout << cnt << "\n";
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