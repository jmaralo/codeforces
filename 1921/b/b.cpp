#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    int n;
    cin >> n;

    string s, f;
    cin >> s >> f;

    int cs = 0, cf = 0, swps = 0, swpf = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cs++;
        if (f[i] == '1')
            cf++;

        if (s[i] == '1' && f[i] == '0')
            swps++;
        if (f[i] == '1' && s[i] == '0')
            swpf++;
    }

    if (cs > cf)
    {
        cout << swpf + (cs - cf) << "\n";
    }
    else if (cs < cf)
    {
        cout << swps + (cf - cs) << "\n";
    }
    else
    {
        cout << swpf << "\n";
    }
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