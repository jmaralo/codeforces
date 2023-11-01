#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    int u, v;
    vector<vector<pair<int, int>>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[--u].push_back({--v, i});
        tree[v].push_back({u, i});
    }

    int mx_depth = 0;
    unordered_set<int> visited;
    stack<pair<int, pair<int, int>>> dfs;
    dfs.push({0, {1, -1}});
    while (!dfs.empty()) {
        pair<int, pair<int, int>> curr = dfs.top();
        dfs.pop();
        if (visited.count(curr.first)) continue;
        visited.insert(curr.first);
        mx_depth = max(mx_depth, curr.second.first);
        for (int i = 0; i < tree[curr.first].size(); i++) {
            pair<int, int> node = tree[curr.first][i];
            dfs.push({node.first, {node.second > curr.second.second ? curr.second.first : curr.second.first + 1, node.second}});
        }
    }

    cout << mx_depth << "\n";
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