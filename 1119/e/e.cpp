#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n), iso(n), alone(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            iso[0] = a[0] / 2;
            alone[0] = a[0] % 2;
            continue;
        }

        iso[i] = iso[i - 1] + (a[i] / 2);
        alone[i] = alone[i - 1] + (a[i] % 2);
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