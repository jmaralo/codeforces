#include <bits/stdc++.h>

using namespace std;

void solve(const size_t &test) {
    size_t n;
    cin >> n;

    size_t color;
    unordered_map<size_t, size_t> color_count;
    for (size_t i{0}; i < n; ++i) {
        cin >> color;
        color_count[color]++;
    }

    vector<size_t> counts;
    for (const auto &[_, count] : color_count) {
        counts.emplace_back(count);
    }
    sort(counts.begin(), counts.end());

    bool alice_moves_next{true};
    size_t alice_score{0};
    for (size_t i{0}; i < counts.size(); ++i) {
        if (alice_moves_next) {
            if (counts[i] == 1) {
                alice_score += 2;
            } else {
                ++alice_score;
            }
            alice_moves_next = counts[i] % 2 == 0;
        } else {
            if (counts[i] != 1) {
                ++alice_score;
            }
            alice_moves_next = counts[i] % 2 == 1;
        }
    }

    cout << alice_score << "\n";
}

int main() {
    size_t test_cases;
    cin >> test_cases;

    for (size_t test{0}; test < test_cases; ++test) {
        solve(test);
    }

    return 0;
}