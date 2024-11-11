#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

pair<int, pair<int, int>> best_result_in_range(int a[], int l, int r, int twos,
                                               bool positive) {
    if (positive) {
        return {twos, {l, r}};
    }

    int best_prefix = twos;
    int best_l;
    for (best_l = l; best_l < r; best_l++) {
        if (a[best_l] == 2 || a[best_l] == -2) --best_prefix;
        if (a[best_l] < 0) {
            ++best_l;
            break;
        }
    }

    int best_suffix = twos;
    int best_r;
    for (best_r = r - 1; best_r >= l; best_r--) {
        if (a[best_r] == 2 || a[best_r] == -2) --best_suffix;
        if (a[best_r] < 0) {
            --best_r;
            break;
        }
    }

    if (best_prefix > best_suffix) {
        return {best_prefix, {best_l, r}};
    } else {
        return {best_suffix, {l, best_r + 1}};
    }
}

#define TESTCASES true
void solve(ull tt) {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    pair<int, pair<int, int>> result{0, {0, 0}};

    int j = 0;
    int twos = 0;
    bool positive = true;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            positive = !positive;
        }
        if (a[i] == 2 || a[i] == -2) {
            ++twos;
        } else if (a[i] == 0) {
            pair<ll, pair<int, int>> possible_ressult =
                best_result_in_range(a, j, i, twos, positive);
            if (possible_ressult.first > result.first)
                result = possible_ressult;
            while (i < n && a[i] == 0) i++;
            j = i;
            twos = (a[i] == 2 || a[i] == -2) ? 1 : 0;
            positive = a[i] > 0;
        }
    }
    if (j < n) {
        pair<ll, pair<int, int>> possible_ressult =
            best_result_in_range(a, j, n, twos, positive);
        if (possible_ressult.first > result.first) result = possible_ressult;
    }

    cout << result.second.first << " " << n - result.second.second << "\n";
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