#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    unsigned int height, width;
    cin >> height >> width;

    if (width <= 3) {
        cout << height << "\n";
    } else if (width % 2 == 0) {
        cout << height * (width / 2) << "\n";
    } else {
        cout << height * (((width - 3) / 2) + 1) << "\n";
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