#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt) {
    string pin;
    cin >> pin;

    int total = 0;
    int curr = 1;
    for (int i = 0; i < pin.size(); i++) {
        int next = pin[i] - '0';
        if (next == 0) next = 10;
        total += abs(next - curr);
        curr = next;
        total++;
    }

    cout << total << "\n";
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