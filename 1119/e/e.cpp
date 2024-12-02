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

    int result{0};

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        result += a[i] / 3;
        a[i] %= 3;
    }

    int nez_i{n - 2};
    for (int i = n - 1; i >= 0; --i) {
        if (i <= nez_i) nez_i = i - 1;
        if (a[i] == 2) {
            while (nez_i >= 0 && a[nez_i] == 0) --nez_i;
            if (nez_i < 0) break;
            --a[nez_i];
            ++result;
        } else if (a[i] == 1) {
            while (nez_i >= 0 && a[nez_i] == 0) --nez_i;
            if (nez_i < 0) break;
            int aux_nez_i{nez_i - 1};
            while (aux_nez_i >= 0 && a[aux_nez_i] == 0) --aux_nez_i;
            if (aux_nez_i < 0) continue;
            --a[nez_i];
            --a[aux_nez_i];
            ++result;
        }
        a[i] = 0;
    }

    cout << result << "\n";
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