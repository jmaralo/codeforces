#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    multiset<int> b;
    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        b.insert(v);
    }

    for (int i = 0; i < n; i++) {
        auto item = b.begin();
        auto best = b.lower_bound((n - a[i]) % n);
        if (best != b.end())
            item = best;
        if (item == b.end()) continue;
        cout << (a[i] + *item) % n << " ";
        b.erase(item);
    }
    cout << "\n";
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