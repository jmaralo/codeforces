#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;
    long long mnf = INT_MAX, mns = INT_MAX, mnb = INT_MAX;
    for (int i = 0; i < n; i++) {
        long long mt;
        cin >> mt;
        string s;
        cin >> s;

        if (s == "10") {
            mnf = min(mnf, mt);
        } else if (s == "01") {
            mns = min(mns, mt);
        } else if (s == "11") {
            mnb = min(mnb, mt);
        }
    }

    if ((mnf == INT_MAX || mns == INT_MAX) && mnb == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min(mnf + mns, mnb) << "\n";
    }
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