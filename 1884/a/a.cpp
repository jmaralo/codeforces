#include <bits/stdc++.h>

using namespace std;

long long digit_sum(long long x) {
    long long r = 0;
    while (x > 0) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

#define TESTCASES true
void solve(int tt) {
    long long x, k;
    cin >> x >> k;

    while(digit_sum(x) % k != 0) {
        x++;
    }

    cout << x << "\n";
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