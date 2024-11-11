#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

#define TESTCASES true

int query(int i, int j) {
    static int resp{};

    cout << "? " << i << " " << j << "\n";
    cout.flush();
    cin >> resp;
    return resp;
}

void solve(ull tt) {
    int n;
    cin >> n;

    int edge_i{0};
    pair<int, int> edges[n - 1]{};

    for (int i{2}; i <= n; i++) {
        int j = 1;
        int resp = query(j, i);
        while (resp != j) {
            j = resp;
            resp = query(j, i);
        }
        edges[edge_i++] = {j, i};
    }

    cout << "! ";
    for (auto &[a, b] : edges) {
        cout << a << " " << b << " ";
    }
    cout << "\n";
    cout.flush();
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