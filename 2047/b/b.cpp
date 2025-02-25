#include <bits/stdc++.h>

using namespace std;

void solve(size_t t) {
    size_t n;
    cin >> n;

    string s;
    cin >> s;

    pair<char, size_t> max_count{'\0', 0};
    unordered_map<char, size_t> count;
    for (size_t i{0}; i < n; ++i) {
        ++count[s[i]];

        if (count[s[i]] > max_count.second) {
            max_count = {s[i], count[s[i]]};
        }
    }

    pair<char, size_t> min_count{'\0', SIZE_MAX};
    for (const auto &[c, cnt] : count) {
        if (cnt < min_count.second && c != max_count.first) {
            min_count = {c, cnt};
        }
    }

    for (size_t i{0}; i < n; ++i) {
        if (s[i] == min_count.first) {
            s[i] = max_count.first;
            break;
        }
    }

    cout << s << "\n";
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t t{0}; t < tt; ++t) {
        solve(t);
    }

    return 0;
}