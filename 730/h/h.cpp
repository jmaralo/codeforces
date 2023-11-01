#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<string> files(n);
    for (int i = 0; i < n; ++i) cin >> files[i];

    vector<int> del(m);
    for (int i = 0; i < m; ++i) {
        cin >> del[i];
        del[i]--;
    }

    string pattern = files[del[0]];
    for (int i = 1; i < m; ++i) {
        if (pattern.size() != files[del[i]].size()) {
            cout << "No\n";
            return;
        }

        for (int j = 0; j < pattern.size(); ++j) {
            if (pattern[j] != '?' && pattern[j] != files[del[i]][j]) {
                pattern[j] = '?';
            }
        }
    }

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j < m && i == del[j]) {
            j++;
            continue;
        }

        if (pattern.size() != files[i].size()) continue;

        bool match = true;
        for (int k = 0; k < pattern.size(); ++k) {
            if (pattern[k] != '?' && pattern[k] != files[i][k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n" << pattern << "\n";
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