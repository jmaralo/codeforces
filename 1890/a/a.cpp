#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    int a;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        cin >> a;
        count[a]++;
    }

    if (count.size() > 2) {
        cout << "No\n";
        return;
    } else if (count.size() == 1) {
        cout << "Yes\n";
        return;
    }

    vector<int> v(2);
    int i = 0;
    for (auto [_, c]: count) {
        v[i++] = c;
    }

    if (abs(v[0] - v[1]) > 1 ) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
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