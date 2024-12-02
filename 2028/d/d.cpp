#include <bits/stdc++.h>

using namespace std;

enum players: uint8_t {
    Queen,
    King,
    Jack,
    None,
}

void solve(const size_t &t) {
    size_t n;
    cin >> n;

    vector<size_t> queen(n);
    for (size_t i{0}; i < n; ++i) cin >> queen[i];

    vector<size_t> king(n);
    for (size_t i{0}; i < n; ++i) cin >> king[i];

    vector<size_t> jack(n);
    for (size_t i{0}; i < n; ++i) cin >> jack[i];

    vector<vector<pair<size_t, players>>> adj(n);
    for (size_t i{0}; i < n; ++i) {
        for (size_t j{i + 1}; j < n; ++j) {
            if (queen[j] < queen[i])
                adj[i].emplace_back(j, Queen);
            else if (king[j] < king[i])
                adj[i].emplace_back(j, King);
            else if (jack[j] < jack[i])
                adj[i].emplace_back(j, Jack);
        }
    }

    bool has_solution{false};
    vector<bool> visited(n, false);
    stack<pair<size_t, size_t>> search;
    search.emplace(0, None);
    while (!search.empty()) {
        auto [node, _] = search.top();
        search.pop();

        if (visited[node]) continue;
        visited[node] = true;

        if (node == n - 1) {
            has_solution = true;
            break;
        }

        for (auto [next, _] : adj[node]) {
            search.emplace(next, node);
        }
    }

    if (!has_solution) {
        cout << "NO\n";
        return;
    }
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t t{0}; t < tt; ++t) solve(t);

    return 0;
}