#include <bits/stdc++.h>

using namespace std;

void solve(int tt) {
    size_t n, k;
    cin >> n >> k;

    vector<size_t> permutation(n, -1);
    size_t next_min_number = 1;
    size_t next_max_number = n;
    
    for(size_t i = 0; i < k; i++) {
        size_t pointer = i;
        while (pointer < n) {
            if (i % 2 == 0) {
                permutation[pointer] = next_min_number++;
            } else {
                permutation[pointer] = next_max_number--;
            }
            pointer += k;
        }
    }

    for (size_t i = 0; i < n; i++) {
        cout << permutation[i] << " ";
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