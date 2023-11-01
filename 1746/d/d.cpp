#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    vector<int> tree(n, -1);
    for (int i = 1; i < n; i++) {
        cin >> tree[i];
        tree[i]--;
    }

    vector<int> score(n);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    vector<pair<vector<int>, int>> t(n);
    for (int i = 0; i < n; i++) {
        t[i].second = score[i];
        if (tree[i] != -1)
            t[tree[i]].first.push_back(i);
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