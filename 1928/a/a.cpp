#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void solve(int tt)
{
    uint a, b;
    cin >> a >> b;

    if (a % 2 == 0)
    {
        if (a / 2 != b || 2 * b != a)
        {
            cout << "Yes\n";
            return;
        }
    }

    if (b % 2 == 0)
    {
        if (b / 2 != a || 2 * a != b)
        {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
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