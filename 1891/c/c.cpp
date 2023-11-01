#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int i = 0, j = n;
    int total = 0, c = 0;
    while (i < j) {
        if (a[i] + c >= a[j - 1]) {
            if (i == (j - 1)) {
                if (c == 0) total += a[i];
                else total += (1 + ((a[i] - c - 1) / 2)) + 1;
                break;
            }
            total += a[j - 1] - c + 1;
            a[i] -= a[j - 1] - c;
            c = 0;
            j--;
        }
        total += a[i];
        c += a[i];
        i++;
    }

    cout << total << "\n";
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