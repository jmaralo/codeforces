#include <bits/stdc++.h>

using namespace std;

struct shoot {
    int t;
    int d;
    int coord;
};

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = i + j;
        }
    }

    int r;
    cin >> r;

    for (int i = 0; i < n; i++) {
        int t, d, coord;
        cin >> t >> d >> coord;
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