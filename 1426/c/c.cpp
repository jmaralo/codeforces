#include <bits/stdc++.h>

using namespace std;

void solve(int tt) {
    int n;
    cin >> n;
    int s = floor(sqrt(n)), d = floor(n / s);
    int sum = s + d - 2;
    if (s * d != n)
        sum++;
    cout << sum << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}