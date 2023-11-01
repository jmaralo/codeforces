#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    string s[2];
    cin >> s[0] >> s[1];

    int n = s[0].size();

    int t, q;
    cin >> t >> q;

    vector < vector <
        for (int i = 0; i < q; i++) {
        int query;
        cin >> query;

        switch (query) {
            case 1:
                int pos;
                cin >> pos;

                blocked[pos - 1] = i + t - 1;
                break;
            case 2:
                int a, pos1, b, pos2;
                cin >> a >> pos1 >> b >> pos2;
                swap(s[a - 1][pos1 - 1], s[b - 1][pos2 - 1]);
                break;
            case 3:
                bool eq = true;
                for (int j = 0; eq && j < n; j++) {
                    if (blocked[j] < i && s[0][j] != s[1][j]) {
                        eq = false;
                    }
                }

                if (eq)
                    cout << "YES\n";
                else
                    cout << "NO\n";
                break;
        }
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