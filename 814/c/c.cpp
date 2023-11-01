#include <bits/stdc++.h>

using namespace std;

void tcase(int n, string s, int m, char c) {
    int a = 0, b = 0, invalid = 0, mx = 0;
    while (b < n) {
        while (b < n && (invalid < m || s[b] == c))
            if (s[b++] != c) invalid++;
        mx = max(mx, b - a);
        while (a < b && invalid >= m)
            if (s[a++] != c) invalid--;
        mx = max(mx, b - a);
    }

    cout << mx << "\n";
}

#define TESTCASES false
void solve(int tt) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q;
    cin >> q;

    int m;
    char c;
    for (int i = 0; i < q; i++) {
        cin >> m >> c;
        tcase(n, s, m, c);
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