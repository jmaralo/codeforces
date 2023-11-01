#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    char prev = s[0];
    bool good = true;
    char cas = '\0'; 
    for (int i = 1; i < n; i++) {
        if (prev == s[i]) {
            good = false;
            if (cas == '\0') {
                cas = s[i];
            } else if (cas != s[i]) {
                cout << "No\n";
                return;
            }
        }
        prev = s[i];
    }

    if (good) {
        cout << "Yes\n";
        return;
    }

    if (t[0] != t[m - 1] || t[0] == cas) {
        cout << "No\n";
        return;
    }

    prev = t[0];
    good = true;
    for (int i = 1; i < m; i++) {
        if (prev == t[i]) {
            good = false;
        }
        prev = t[i];
    }

    if (good) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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