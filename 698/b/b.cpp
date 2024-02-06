#include <bits/stdc++.h>

using namespace std;


size_t flatten(vector<size_t> &parents, vector<bool> &visited, size_t node) {
    if (visited[node]) {
        return parents[node];
    }
    visited[node] = true;

    if (parents[node] - 1 != node) {
        parents[node] = flatten(parents, visited, parents[node] - 1);
    }

    return parents[node];
}

unordered_set<size_t> find_unique_elements(vector<size_t> &vec) {
    unordered_set<size_t> unique;
    for (auto value = vec.begin(); value != vec.end(); value++) {
        unique.insert(*value);
    }
    return unique;
}

void solve(int tt) {
    size_t n;
    cin >> n;

    vector<size_t> parents(n);
    vector<size_t> dsu(n);
    for (size_t i = 0; i < n; i++) {
        cin >> parents[i];
        dsu[i] = parents[i];
    }

    vector<bool> visited(n, false);
    for (size_t i = 0; i < n; i++) {
        flatten(dsu, visited, i);
    }

    unordered_set<size_t> unique_roots = find_unique_elements(dsu);

    size_t global_root = -1;
    for (auto root = unique_roots.begin(); root != unique_roots.end(); root++) {
        if (parents[*root - 1] == *root) {
            global_root = *root;
            break;
        }
    }

    cout << unique_roots.size() - (global_root != -1 ? 1 : 0) << "\n";

    if (global_root == -1) {
        global_root = *unique_roots.begin();
    }

    for (auto root = unique_roots.begin(); root != unique_roots.end(); root++) {
        parents[*root - 1] = global_root;
    }

    for (size_t i = 0; i < n; i++) {
        cout << parents[i] << " ";
    }
    cout << "\n";
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