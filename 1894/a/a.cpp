#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    char w = s[n - 1];
    int w_count = 1;
    for (int i = 0; i < n - 1; i++) if (s[i] == w) w_count++;

    int l_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != w) {
            l_count++;
        } else {
            break;
        }
    }

    if (l_count >= w_count) {
        cout << "?\n";
    } else {
        cout << w << "\n";
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