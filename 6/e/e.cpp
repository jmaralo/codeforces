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
    uint k;
    cin >> n >> k;

    vector<pair<uint, size_t>> h(n);
    for (size_t i = 0; i < n; i++) {
        uint h_;
        cin >> h_;
        h[i] = {h_, i};
    }
    
    multiset<
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