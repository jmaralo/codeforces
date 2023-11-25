#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    size_t n;
    cin >> n;

    vector<unsigned int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    unsigned long long diff = 0;
    for (size_t i = 1; i < n; i++) {
        diff += a[i] - a[i - 1];
    }

    vector<unsigned int> ops(0);
    while (diff != 0) {
        vector<unsigned int> b(a.begin(), a.end());
        for (size_t i = 0; i < n; i++) {
            b[i] = a[i] / 2;
        }
        
        unsigned long long diff_b = 0;
        for (size_t i = 1; i < n; i++) {
            diff_b += b[i] - b[i - 1];
        }

        vector<unsigned int> c(a.begin(), a.end());
        for (size_t i = 0; i < n; i++) {
            c[i] = (a[i] + 1) / 2;
        }

        unsigned long long diff_c = 0;
        for (size_t i = 1; i < n; i++) {
            diff_c += c[i] - c[i - 1];
        }

        if (diff_b < diff_c) {
            a = b;
            diff = diff_b;
            ops.push_back(0);
        } else {
            a = c;
            diff = diff_c;
            ops.push_back(1);
        }
    }

    cout << ops.size() << "\n";
    if (ops.size() && ops.size() <= n) {
        for (size_t i = 0; i < ops.size(); i++) {
            cout << ops[i] << " ";
        }
        cout << "\n";
    }
}

#define TESTCASES true
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