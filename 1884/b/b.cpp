#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    string b;
    cin >> b;

    long long total = 0;
    int i = n - 1, j = n - 1;
    while (i >= 0) {
        if (b[j] == '0') {
            cout << "0 ";
            j--;
            i--;
        } else {
            i--;
            break;
        }
    }

    while (i >= 0) {
        while (i >= 0 && b[i] == '1') i--;
        if (i < 0) break;
        b[i] = '1';
        total += j - i;
        cout << total << " ";
        j--;
        i--;
    }

    while (j >= 0) {
        cout << "-1 ";
        j--;
    }

    cout << "\n";

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