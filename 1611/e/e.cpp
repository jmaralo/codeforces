#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> &tree, int start, int n, vector<int> &mx) {
    unordered_set<int> visited;
    vector<int> depth(n, -1);
    queue<pair<int, int>> bfs;
    bfs.push({start, 0});
    while (!bfs.empty()) {
        pair<int, int> curr = bfs.front();
        bfs.pop();
        if (visited.count(curr.first)) continue;
        visited.insert(curr.first);
        depth[curr.first] = curr.second;
        for (int i = 0; i < tree[curr.first].size(); i++)
            if (curr.second + 1 <= mx[tree[curr.first][i]])
                bfs.push({tree[curr.first][i], curr.second + 1});
    }
    return depth;
}

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> friends(k);
    for (int i = 0; i < k; i++)
        cin >> friends[i];

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> mx_depth(n, INT_MAX);
    vector<int> depth = bfs(tree, 0, n, mx_depth);

    map<int, int> req;
    for (int i = 0; i < n; i++) {
        req[depth[i]]++;
    }

    int mx = 0;
    for (auto [d, a] : req)
        if (a <= k)
            mx = d;
        else
            break;

    for (int i = 0; i < n; i++)
        depth[i] = depth[i] > mx ? -1 : depth[i];

    vector<int> mn(n, INT_MAX);
    for (int i = 0; i < k; i++) {
        vector<int> dpth = bfs(tree, friends[i], n, depth);
        for (int j = 0; j < n; j++) {
            mn[j] = min(mn[j], dpth[j]);
        }
    }

    vector<pair<int, int>> comb(n);
    for (int i = 0; i < n; i++) {
        comb[i] = {depth[i], mn[i]};
    }
    sort(comb.begin(), comb.end());

    int d = comb[0].first;
    bool valid = true;
    for (int i = 0; i < n; i++) {
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