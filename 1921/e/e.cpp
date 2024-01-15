#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;

    int dc = xb - xa;
    if (dc <= 0)  {
        cout << "Draw\n";
        return;
    }

    int r = xa + 1 + ((dc - 1) / 2);

    int la = max(ya - (r - xa), 1), ra = min(ya + (r - xa), w);
    int lb = max(yb - (xb - r), 1), rb = min(yb + (xb - r), w);

    if (dc % 2 == 0 && (lb <= la) && (rb >= ra)) cout << "Bob\n";
    else if (dc % 2 == 1 && (la <= lb) && (ra >= rb)) cout << "Alice\n";
    else cout << "Draw\n";
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