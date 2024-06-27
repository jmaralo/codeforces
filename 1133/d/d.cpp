#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

#define TESTCASES false
void solve(ull tt) {
    size_t n;
    cin >> n;

    vector<int> a(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n);
    for (size_t i = 0; i < n; i++) cin >> b[i];

    map<pair<int, int>, size_t> count;
    size_t max_count = 0;

    size_t zeros = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) zeros++;
            continue;
        }

        int divisor = gcd(a[i], b[i]);
        pair<int, int> fraction = {a[i] / divisor, b[i] / divisor};
        if (a[i] < 0)
            fraction = {(-a[i]) / divisor, (-b[i]) / divisor};

        count[fraction]++;

        max_count = max(max_count, count[fraction]);
    }

    cout << zeros + max_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES) {
        solve(0);
        return 0;
    }

    ull t;
    cin >> t;
    for (ull i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}