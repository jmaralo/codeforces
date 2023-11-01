#include <bits/stdc++.h>

using namespace std;

int moves(string &s, int a, int b, char c) {
    if (b - a == 1) return s[a] != c ? 1 : 0;

    int mid = (a + b) / 2;
    int cl = 0;
    for (int i = a; i < mid; i++)
        if (s[i] == c) cl++;

    int cr = 0;
    for (int i = mid; i < b; i++)
        if (s[i] == c) cr++;

    return min(((b - a) / 2) - cl + moves(s, mid, b, c + 1), ((b - a) / 2) - cr + moves(s, a, mid, c + 1));
}

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << moves(s, 0, n, 'a') << "\n";
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