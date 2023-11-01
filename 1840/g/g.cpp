#include <bits/stdc++.h>

using namespace std;

int cw(int n) {
    cout << "+ " << n << "\n";
    cout.flush();

    int next;
    cin >> next;
    return next;
}

int ccw(int n) {
    cout << "- " << n << "\n";
    cout.flush();

    int next;
    cin >> next;
    return next;
}

#define TESTCASES false
void solve(int tt) {
    int x;
    cin >> x;

    int prev = x, next = cw(x);
    while (next > prev) {
        prev = next;
        next = cw(prev);
        }

    cout << "! " << prev + (prev - next) << "\n";
    cout.flush();
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