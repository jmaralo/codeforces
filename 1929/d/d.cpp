#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

#define MOD 998244353

void solve(int tt)
{
    ull nodes;
    cin >> nodes;

    unordered_map<ull, ull> degree;
    ull node_u, node_v;
    for (ull i = 0; i < nodes - 1; i++)
    {
        cin >> node_u >> node_v;
        degree[node_u]++;
        degree[node_v]++;
    }

    ull good_nodes = 0;
    for (auto it = degree.begin(); it != degree.end(); it++)
        if (it->second <= 1)
            good_nodes++;

    ull answer = (nodes * (nodes + 1) / 2) % MOD;

    ull answer_good = 1;
    for (size_t i = 0; i < good_nodes; i++)
        answer_good = (2 * answer_good) % MOD;

    answer_good = (answer_good - (good_nodes * (good_nodes + 1) / 2)) % MOD;

    cout << (answer + answer_good) % MOD << "\n";
}

#define TESTCASES true
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES)
    {
        solve(0);
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve(i + 1);
    }
    return 0;
}