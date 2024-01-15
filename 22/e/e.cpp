#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    int n;
    cin >> n;

    vector<bool> in(n, false);
    int u = -1;
    int count = n;
    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        v--;
        if (in[v]) continue;
        if (u == -1) u = v;
        count--;
        in[v] = true;
    }

    cout << count << "\n";
    for (int i = 0; i < n; i++) {
        if (in[i]) continue;
        cout << u + 1 << " " << i + 1 << "\n";
    }
}

#define TESTCASES false
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