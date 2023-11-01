#include <bits/stdc++.h>

using namespace std;

int hbs(int a) {
    int i = 0;
    while (a != 0) {
        a >>= 1;
        i++;
    }
    return i;
}

#define TESTCASES true
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    int i = hbs(n);
    if (i <= k) {
        cout << n + 1 << "\n";
        return;
    }

    cout << (long long)(pow(2, k)) << "\n";
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