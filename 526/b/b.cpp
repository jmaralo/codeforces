#include <bits/stdc++.h>

using namespace std;

pair<int, int> rec(vector<int> &l, int n, int n2) {
    if (n >= (n2 - 1)) {
        return {0, l[n]};
    }

    pair<int, int> a = rec(l, (n * 2) + 1, n2), b = rec(l, (n * 2) + 2, n2);

    return {
        a.first + b.first + (max(a.second, b.second) - min(a.second, b.second)),
        max(a.second, b.second) + l[n],
    };
}

#define TESTCASES false
void solve(int tt) {
    int n;
    cin >> n;

    int n2 = pow(2, n);

    vector<int> l((n2 * 2) - 1, 0);
    for (int i = 1; i < l.size(); i++) {
        cin >> l[i];
    }

    cout << rec(l, 0, n2).first << "\n";

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