#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int mn = v[0];
    for (int i = 1; i < n; i++) mn &= v[i];

    if (mn != 0) {
        cout << "1\n";
        return;
    }

    int g = 0, curr = ~0;
    for (int i = 0; i < n; i++) {
        curr &= v[i];
        if (curr == mn) {
            g++;
            curr = ~0;
        }
    }

    cout << g << "\n";
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