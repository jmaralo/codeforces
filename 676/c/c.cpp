#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int mxa = 0, i = 0, j = 0, c = 0;
    while (j < s.size() && i < s.size()) {
        if (c < k || (c == k && s[j] == 'a')) {
            if (s[j] == 'b') {
                c++;
            }

            j++;
        } else {
            if (s[i] == 'b') {
                c--;
            }

            i++;
        }
        mxa = max(mxa, j - i);
    }
    mxa = max(mxa, j - i);

    int mxb = 0;
    i = 0, j = 0, c = 0;
    while (j < s.size() && i < s.size()) {
        if (c < k || (c == k && s[j] == 'b')) {
            if (s[j] == 'a') {
                c++;
            }

            j++;
        } else {
            if (s[i] == 'a') {
                c--;
            }

            i++;
        }
        mxb = max(mxb, j - i);
    }
    mxb = max(mxb, j - i);

    cout << max(mxa, mxb) << "\n";
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