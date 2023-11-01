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

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> swaps;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1] || (a[j] == a[j + 1] && b[j] > b[j + 1])) {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                swaps.push_back({j, j + 1});
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1] || b[i] > b[i + 1]) {
            cout << "-1\n";
            return;
        }
    }

    cout << swaps.size() << "\n";
    for (int i = 0; i < swaps.size(); i++) {
        cout << swaps[i].first + 1 << " " << swaps[i].second + 1 << "\n";
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