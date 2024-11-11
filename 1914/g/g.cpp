#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

class dsu {
    vector<size_t> parents;
    vector<size_t> sizes;

   public:
    dsu(size_t elements) : parents(elements), sizes(elements) {
        for (size_t i = 0; i < elements; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    void union_set(size_t a, size_t b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizes[a] < sizes[b]) {
                swap(a, b);
            }
            parents[b] = a;
            sizes[a] += sizes[b];
        }
    }

    size_t find_set(size_t a) {
        if (a == parents[a])
            return a;
        return parents[a] = find_set(parents[a]);
    }

    vector<size_t> get_sets() {
        return parents;
    }
};

#define TESTCASES true
void solve(ull tt) {
    size_t n;
    cin >> n;

    vector<size_t> c(2 * n);
    unordered_set<size_t> parents;
    vector<unordered_set<size_t>> graph(n);
    for (size_t i = 0; i < 2 * n; i++) {
        cin >> c[i];
        c[i]--;

        if (parents.count(c[i]))
            parents.erase(c[i]);
        else
            parents.insert(c[i]);

        for (size_t parent : parents)
            if (parent != c[i]) graph[parent].insert(c[i]);
    }

    dsu sets(n);
    for (size_t i = 0; i < n; i++)
        for (size_t child : graph[i])
            sets.union_set(i, child);

    vector<size_t> graph_sets = sets.get_sets();
    unordered_map<size_t, size_t> answer_components;
    for (size_t i = 0; i < n; i++)
        if (graph[i].size() > 0) answer_components[graph_sets[i]]++;

    size_t total_ans = 1;
    for (auto [_, parents] : answer_components) {
        total_ans *= parents * 2;
    }
    cout << answer_components.size() << " " << total_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES) {
        solve(0);
        return 0;
    }

    ull t;
    cin >> t;
    for (ull i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}