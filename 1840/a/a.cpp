#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = 1;
    char c = s[0];
    string a;
    while (i < n) {
        if (s[i] == c) {
            a += c;
            if (i < n - 1)
                c = s[++i];
        }
        i++;
    }

    cout << a << "\n";
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