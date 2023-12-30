#include <bits/stdc++.h>

using namespace std;

void solve(int tt) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = s.size() - 1;
    while (i >= 0 && s[i] == 'A') i--;

    int j = i, ans = 0;
    for (; i >= 0; i--) {
        if (s[i] == 'A') {
            ans += j - i;
            j = i;
        }
    }

    cout << ans << "\n";
}

#define TESTCASES true
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