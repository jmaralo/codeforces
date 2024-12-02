#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

#define TESTCASES true
void solve(ull tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i{0}; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = (a[n - 1] - a[0]) + (a[n - 1] - a[1]) + (a[n - 2] - a[0]) +
              (a[n - 2] - a[1]);

    cout << ans << "\n";
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