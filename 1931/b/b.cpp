#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve(int tt)
{
    size_t n;
    cin >> n;

    vector<ull> water(n);
    ull sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> water[i];
        sum += water[i];
    }
    ull waterPerContainer = sum / n;

    ull overflow = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (water[i] + overflow >= waterPerContainer)
        {
            overflow = water[i] + overflow - waterPerContainer;
        }
        else
        {
            cout << "NO\n";
            return;
        }
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