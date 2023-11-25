#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    size_t n;
    cin >> n;

    vector<unsigned int> a(n);
    unordered_map<unsigned int, unordered_set<size_t>> b;
    unsigned int mx = 0;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]].insert(i);
        mx = max(mx, a[i]);
    }

    unsigned long long power = ULONG_LONG_MAX;
    for (size_t m: b[mx]) {
        long long i = m - 1, j = m + 1;
        unsigned long long curr_p = mx - 1, p = mx;
        while (i >= 0 || j < n) {
            if (i < 0) {
                if (curr_p < a[j]) {
                    p += a[j] - curr_p;
                    curr_p = a[j];
                }
                j++;
            } else if (j >= n) {
                if (curr_p < a[i]) {
                    p += a[i] - curr_p;
                    curr_p = a[i];
                }
                i--;
            } else if (a[i] <= a[j]) {
                if (curr_p < a[i]) {
                    p += a[i] - curr_p;
                    curr_p = a[i];
                }
                i--;
            } else if (a[j] < a[i]) {
                if (curr_p < a[j]) {
                    p += a[j] - curr_p;
                    curr_p = a[j];
                }
                j++;
            }
            curr_p--;
        }
        power = min(p, power);
    }

    cout << power << "\n";
}

#define TESTCASES false
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