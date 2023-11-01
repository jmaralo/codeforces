#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> am(n + 1);
    for (int i = 0; i < n; i++) {
        am[nums[i]]++;
    }

    int curr = 0;
    for (int i = 0; i <= n; i++) {
        curr += am[i];
        if (curr + i == n) {
            cout << i << "\n";
            return;
        }
    }

    cout << "-1\n";
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