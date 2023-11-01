#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    int v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v;
            if (((i + j) % 2 && !(v % 2)) || (!((i + j) % 2) && v % 2))
                cout << v + 1 << " ";
            else
                cout << v << " ";
        }
        cout << "\n";
    }
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