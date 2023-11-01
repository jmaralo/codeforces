#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES false
void solve(int tt) {
    int n, s;
    cin >> n >> s;

    int u = (1 + ((s - 1) / 9)) * 10;

    cout << max(0, n - u + 1) << "\n";
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