#include <bits/stdc++.h>

using namespace std;

long long pow_mod(long long a, long long b, long long n) {
    long long res = 1;
    while (b != 0) {
        if (b & 1 == 1) res = (res * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return res;
}

const long long MOD = 1000000007;

#define TESTCASES true
void solve(int tt) {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << (pow_mod(k, m - n, MOD) * (((n * (m - n)) % MOD) + 1)) % MOD << "\n";
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