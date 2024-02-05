#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void solve(int tt)
{
    uint n;
    cin >> n;

    vector<pair<uint, uint>> p(n, {0, 0});
    for (uint i = 0; i < n; i++)
        cin >> p[i].first;

    for (uint i = 0; i < n; i++)
        cin >> p[i].second;

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        cout << p[i].first << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << p[i].second << " ";
    }
    cout << "\n";
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