#include <bits/stdc++.h>

using namespace std;

vector<int> find_longest(vector<int> &a, int n) {
    int v = a[0] - 1, curr = 1;
    vector<int> count(n * 2, 0);
    count[v] = curr;
    for (int i = 1; i < n; i++) {
        if (a[i] - 1 != v) {
            count[v] = max(count[v], curr);
            curr = 0;
            v = a[i] - 1;
        }
        curr++;
    }
    count[v] = max(count[v], curr);
    return count;
}

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> la = find_longest(a, n);

    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> lb = find_longest(b, n);

    int mx = 0;
    for (int i = 0; i < n * 2; i++)
        mx = max(mx, la[i] + lb[i]);

    cout << mx << "\n";
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