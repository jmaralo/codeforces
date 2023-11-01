#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<bool> even(n, false), odd(n, false);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            odd[i] = true;
        } else {
            even[i] = true;
        }

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) continue;
            if (a[i] - a[j] % 2 != 0) {
                even[i] = true;
                break;
            } else if (a[i] - a[j] % 2 == 0) {
                odd[i] = true;
                break;
            }
        }
    }

    bool e = true, o = true;
    for (int i = 0; i < n; i++) {
        e = e && even[i];
        o = o && odd[i];
    }

    if (e || o)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
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