#include <bits/stdc++.h>

using namespace std;

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

    vector<int> bad;
    for (int i = 0; bad.empty() && i < n; i++) {
        vector<int> tmp = grid[i];
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != tmp[j]) bad.push_back(j);
        }
    }

    if (bad.size() == 0) {
        cout << "1 1\n";
        return;
    }

    if (bad.size() > 2) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        swap(grid[i][bad[0]], grid[i][bad[1]]);
        for (int j = 1; j < m; j++) {
            if (grid[i][j] < grid[i][j - 1]) {
                cout << "-1\n";
                return;
            }
        }
    }

    cout << bad[0] + 1 << " " << bad[1] + 1 << "\n";
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