#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    vector<int> valid;
    for (auto [val, c] : count) {
        if (c >= k) valid.push_back(val);
    }

    if (valid.size() == 0) {
        cout << "-1\n";
        return;
    }

    int l = 0, r = 0;
    for (int i = 0; i < valid.size(); i++) {
        int j = i;
        while (i < valid.size() - 1 && valid[i + 1] - 1 == valid[i]) i++;
        if (i - j >= r - l) {
            r = i;
            l = j;
        }
    }

    cout << valid[l] << " " << valid[r] << "\n";
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