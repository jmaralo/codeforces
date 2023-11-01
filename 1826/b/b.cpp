#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    long long n;
    cin >> n;
    long long int a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long int curr = abs(a[0] - a[n - 1]);
    for (long long i = 1; i < n / 2; i++) {
        long long int div = abs(a[i] - a[n - i - 1]);
        if (curr == 0) {
            curr = div;
            continue;
        }

        if (div == 0) continue;

        if (curr > div) {
            if (curr % div == 0) {
                curr = div;
            } else {
                cout << "0\n";
                return;
            }
        } else if (div > curr) {
            if (div % curr != 0) {
                cout << "0\n";
                return;
            }
        }
    }

    cout << curr << "\n";
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