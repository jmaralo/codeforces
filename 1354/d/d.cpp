#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n, q;
    cin >> n >> q;

    map<int, int> m;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        m[val]++;
    }

    int query;
    for (int i = 0; i < q; i++) {
        cin >> query;
        if (query < 0) {
            int idx = (*next(m.begin(), (-query) - 1)).first;
            m[idx]--;
            if (m[idx] <= 0) {
                m.erase(idx);
            }
        } else {
            m[query]++;
        }
    }

    if (m.size() > 0) {
        cout << (*m.begin()).first << "\n";
    } else {
        cout << "0\n";
    }
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