#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    vector<int> t(3);
    for (int i = 0; i < 3; i++)
        cin >> t[i];

    if (t[0] == t[1] && t[0] == t[2]) {
        cout << "YES\n";
        return;
    }

    sort(t.begin(), t.end());
    for (int i = 0; i < 3; i++) {
        if (t[t.size() - 1] <= t[0]) break;
        t.push_back(t[t.size() - 1] - t[0]);
        t[t.size() - 2] = t[0];
        sort(t.begin(), t.end());      
    }

    for (int j = 1; j < t.size(); j++) {
        if (t[j] != t[0]) {
            cout << "NO\n";
            return;
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