#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &test) {
    size_t n;
    int k;
    cin >> n >> k;

    string bob_fishes;
    cin >> bob_fishes;

    vector<int> bob_fishes_since(n);
    bob_fishes_since[n - 1] = bob_fishes[n - 1] == '1' ? 1 : -1;
    for (size_t i{1}; i < n; ++i) {
        bob_fishes_since[n - i - 1] = bob_fishes_since[n - i];
        bob_fishes_since[n - i - 1] += bob_fishes[n - i - 1] == '1' ? 1 : -1;
    }
    sort(bob_fishes_since.rbegin(), prev(bob_fishes_since.rend()));

    int sum = 0;
    for (size_t i{1}; i < n; ++i) {
        if (bob_fishes_since[i] <= 0) {
            break;
        }

        sum += bob_fishes_since[i];

        if (sum >= k) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    size_t test_cases;
    cin >> test_cases;

    for (size_t test{0}; test < test_cases; ++test) {
        solve(test);
    }

    return 0;
}