#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    size_t n;
    cin >> n;

    string cells;
    cin >> cells;

    size_t first_black = -1, last_black = -1;
    for (size_t i = 0; i < n; i++) {
        if (cells[i] == 'W')
            continue;

        last_black = i;
        if (first_black == -1)
            first_black = i;
    }

    cout << last_black - first_black + 1 << "\n";
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