#include <bits/stdc++.h>

using namespace std;


void solve(int tt) {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> good(n, -1);
    deque<int> bad;
    int good_n = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == (i + 1)) {
            good[i] = 0;
            good_n++;
        } else {
            bad.push_front(a[i]);
        }
    }

    int second = 1;
    while (good_n != n) {
        bad.push_back(bad.front());
        bad.pop_front();
        int j = 0;
        deque<int> next;
        while (!bad.empty() && j < n) {
            while (j < n && good[j] != -1) j++;
            if (j >= n) break;
            if (bad.back() == (j + 1)) {
                good[j] = second;
                good_n++;
            } else {
                next.push_front(bad.back());
            }
            bad.pop_back();
            j++;
        }
        bad = next;
        second++;
    }

    for (size_t i = 0; i < n; i++) {
        cout << good[i] << " ";
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