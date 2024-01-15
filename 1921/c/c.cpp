#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    long long n, f, a, b;
    cin >> n >> f >> a >> b;

    vector<long long> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];
    
    long long chg = f;
    long long prev = 0;
    for (int i = 0; i < n; i++) {
        if (chg <= 0) {
            cout << "NO\n";
            return;
        }

        chg -= min((m[i] - prev) * a, b);
        prev = m[i];
    }
    if (chg <= 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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