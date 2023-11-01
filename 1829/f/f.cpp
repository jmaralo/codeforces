#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;
    vector<int> neighs(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        neighs[u - 1]++;
        neighs[v - 1]++;
    }

    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[neighs[i]]++;
    }

    for (auto [neigh, c] : count) {
        if (neigh == 1 || c == 1) continue;
        if (count.size() == 2) {
            cout << c - 1 << " " << neigh - 1 << "\n";
            return;
        }
        cout << c << " " << neigh - 1 << "\n";
        return;
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