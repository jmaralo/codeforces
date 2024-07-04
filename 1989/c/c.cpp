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
    size_t n;
    cin >> n;

    vector<int> a(n);
    for (size_t i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n);
    for (size_t i = 0; i < n; i++) cin >> b[i];

    int sum_a = 0, sum_b = 0;
    int neg = 0, pos = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (b[i] != 1)
                sum_a++;
        } else if (b[i] == 1) {
            if (a[i] != 1)
                sum_b++;
        }

        if (a[i] == -1 && b[i] == -1)
            neg++;
        else if (a[i] == 1 && b[i] == 1)
            pos++;
    }

    while (neg > 0) {
        if (sum_a > sum_b)
            sum_a--;
        else
            sum_b--;
        neg--;
    }

    while (pos > 0) {
        if (sum_a > sum_b)
            sum_b++;
        else
            sum_a++;
        pos--;
    }

    cout << min(sum_a, sum_b) << "\n";
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