#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

#define TESTCASES false
void solve(int tt) {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long g = gcd(x, y);
    while (g != 1) {
        x /= g;
        y /= g;
        g = gcd(x, y);
    }
    cout << min(a / x, b / y) << "\n";
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