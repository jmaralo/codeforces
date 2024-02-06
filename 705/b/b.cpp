#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve(int tt) {
    size_t n;
    cin >> n;

    ull vertices;
    ull vertices_sum = 0;
    for(size_t i = 0; i < n; i++) {
        cin >> vertices;
        vertices_sum += vertices;

        if (vertices_sum % 2 == i % 2) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}

#define TESTCASES false
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