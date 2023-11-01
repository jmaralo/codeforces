#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check_connection(vector<string> &p, vector<vector<int>> &connected, int i, int j, int n) {
    if (i >= n || j >= n) return true;
    if (connected[i][j] != -1) return connected[i][j];
    if (p[i][j] == '0') return false;

    bool rht = check_connection(p, connected, i, j + 1, n);
    bool down = check_connection(p, connected, i + 1, j, n);

    connected[i][j] = rht || down;
    return connected[i][j];
}

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<string> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<vector<int>> connected(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i][j] == '0') continue;

            if (!check_connection(p, connected, i, j, n)) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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