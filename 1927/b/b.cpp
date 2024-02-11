#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    size_t n;
    cin >> n;

    size_t trace;
    unordered_map<size_t, size_t> count;
    for (size_t i = 0; i < n; i++) {
        cin >> trace;
        count[trace]++;
        cout << (char)('a' + (count[trace] - 1));
    }
    cout << "\n";

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