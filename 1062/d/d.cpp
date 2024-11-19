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
    int n;
    cin >> n;

    ull score{0};
    for (int i{2}; i <= n; i++) {
        ull a = n / i;
        ull b = ((a * (a + 1)) / 2) - 1;
        score += b * 4;
    }

    cout << score << "\n";
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