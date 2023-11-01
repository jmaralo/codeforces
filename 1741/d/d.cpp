#include <bits/stdc++.h>

using namespace std;

void swap_part(vector<int>& p, int i, int j, int s) {
    for (int k = 0; k < s; k++) {
        swap(p[i + k], p[j + k]);
    }
}

#define TESTCASES true
void solve(int tt) {
    int m;
    cin >> m;

    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    int s = 1, res = 0;
    while (s <= m / 2) {
        for (int i = 0; i + s < m; i += s * 2) {
            if (p[i] > p[i + s]) {
                swap_part(p, i, i + s, s);
                res++;
            }
        }
        s *= 2;
    }

    for (int i = 1; i < m; i++) {
        if (p[i] < p[i - 1]) {
            cout << "-1\n";
            return;
        }
    }

    cout << res << "\n";
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