#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_set<string> ss;

    for (int i = 0; i < n - 1; i++) {
        ss.insert(s.substr(i, 2));
    }

    cout << ss.size() << "\n";
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