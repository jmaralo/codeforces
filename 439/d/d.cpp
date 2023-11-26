#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES false
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());

    int i = 0;
    while (i < (n - 1) && a[i] == a[i+1]) i++;
    int j = m - 1;
    while (j > 0 && b[j] == b[j - 1]) j--;

    int ops = 0;
    while (i < (n - 1) && j > 0 && a[i] < b[j]) {
        int c_a = (a[i + 1] - a[i]) * (i + 1);
        int c_b = (b[j] - b[j - 1]) * (m - j);

        if (c_a < c_b) {
            ops += c_a;
            i++;
            while (i < (n - 1) && a[i] == a[i+1]) i++;
        } else {
            ops += c_b;
            j--;
            while (j > 0 && b[j] == b[j - 1]) j--;
        }
    }

    if (a[i] >= b[j]) {
        cout << ops << "\n";
        return;
    }

    if (i >= (n - 1)) {
        while (j > 0 && a[i] < b[j]) {
            int c_b = (b[j] - b[j - 1]) * (m - j);
            if ((n * (min(0, (a[i] - b[m - 1])) + 1)) < c_b) {
                ops += n;
                a[i]++;
            } else {
                ops += c_b;
                j--;
                while (j > 0 && b[j] == b[j - 1]) j--;
            }
        }
    } else if (j <= 0) {
        while (i < (n - 1) && a[i] < b[j]) {
            int c_a = (a[i + 1] - a[i]) * (i + 1);
            if (c_a < (m * (min(0, (b[j] - a[n - 1])) + 1))) {
                ops += c_a;
                i++;
                while (i < (n - 1) && a[i] == a[i + 1]) i++;
            } else {
                ops += m;
                b[j]--;
            }
        }
    }

    if (a[i] >= b[j]) {
        cout << ops << "\n";
        return;
    }

    ops += (b[j] - a[i]) * min(n, m);

    cout << ops << "\n";
}

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