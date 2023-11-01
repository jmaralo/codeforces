#include <bits/stdc++.h>

using namespace std;

int size(vector<vector<int>> &grid, int i, int j) {
    queue<pair<int, int>> s;
    s.push({i, j});
    int sz = 0;
    while (!s.empty()) {
        pair<int, int> curr = s.front();
        s.pop();

        if (curr.first < 0 || curr.first >= grid.size() || curr.second < 0 || curr.second >= grid[0].size()) {
            continue;
        }

        if (grid[curr.first][curr.second] == 0) continue;

        s.push({curr.first + 1, curr.second});
        s.push({curr.first - 1, curr.second});
        s.push({curr.first, curr.second + 1});
        s.push({curr.first, curr.second - 1});

        sz += grid[curr.first][curr.second];
        grid[curr.first][curr.second] = 0;
    }

    return sz;
}

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                mx = max(mx, size(grid, i, j));
            }
        }
    }

    cout << mx << "\n";
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