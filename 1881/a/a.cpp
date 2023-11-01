#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    string x;
    cin >> x;

    string s;
    cin >> s;

    int a = -1;
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        if (x[i] == s[0]) {
            found = true;
            a = i;
            for (int j = 0; j < m && found; j++) {
                if (s[j] != x[(i + j) % n]) {
                    found = false;
                }
            }
        }
    }

    if (!found) {
        cout << "-1\n";
        return;
    }

    int l = n, j = 0;
    while (l < (a + m)) {
        l += l;
        j++;
    }

    cout << j << "\n";
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