#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TESTCASES true
void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> gc;
    int gt2 = 0;
    unordered_map<int, bool> gt;
    for (int i = 0; i < n; i++) {
        gc[a[i]]++;
        if (gc[a[i]] == 2) {
            gt2++;
            gt[a[i]] = true;
        }
    }

    if (gt2 < 2) {
        cout << "-1\n";
        return;
    }

    bool three = false;
    for (int i = 0; i < n; i++) {
        gc[a[i]]--;
        if (gc[a[i]] == 0) {
            cout << (three ? "3 " : "2 ");
            if (gt[a[i]]) three = !three;
        } else {
            cout << "1 ";
        }
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