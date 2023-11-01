#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> perm(n);
    perm[n - 1] = 3;
    perm[0] = 2;
    perm[n / 2] = 1;
    for (int i = 1; i < n / 2; i++) {
        perm[i] = i + 3;
    }
    for (int i = (n / 2) + 1; i < n - 1; i++) {
        perm[i] = i + 2;
    }

    for (int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }
    cout << "\n";
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