#include <bits/stdc++.h>

using namespace std;

class dsu {
    vector<int> size;

   public:
    vector<int> classes;

    dsu(int n) {
        size = vector<int>(n, 1);
        classes = vector<int>(n);
        for (int i = 0; i < n; i++) {
            classes[i] = i;
        }
    }

    int find(int x) {
        if (classes[x] == x) {
            return x;
        }
        return classes[x] = find(classes[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y])
                swap(x, y);
            classes[y] = x;
            size[x] += size[y];
        }
    }

    void flatten() {
        for (int i = 0; i < classes.size(); i++) {
            classes[i] = find(i);
        }
    }
};

#define TESTCASES false
void solve(int tt) {
    int n, m;
    cin >> n >> m;

    dsu uf(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        uf.join(u - 1, v - 1);
    }
    uf.flatten();

    vector<pair<int, int>> comb(n);
    for (int i = 0; i < n; i++) {
        comb[i] = {uf.classes[i], i};
    }
    sort(comb.begin(), comb.end());

    unordered_set<int> join;
    for (int i = 0; i < n - 1; i++) {
        if (comb[i].first != comb[i + 1].first || comb[i + 1].second - comb[i].second == 1) continue;
        for (int j = comb[i].second + 1; j < comb[i + 1].second; j++) {
            if (uf.classes[j] > i) {
                join.insert(uf.classes[j]);
                uf.classes[j] = i;
            }
        }
    }

    cout << join.size() << "\n";
}

int main() {
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