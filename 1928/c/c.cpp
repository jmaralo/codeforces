#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void solve(int tt)
{
    uint n, x;
    cin >> n >> x;

    if (n % 2 != x % 2)
    {
        cout << "0\n";
        return;
    }

    uint answer = 0;
    for (uint k = max(uint(2), x); k < n; ++k)
    {
        if (2 * k - 1 - x > n)
        {
            // cout << k << "\n";
            break;
        }

        uint position = (n - 1) % (2 * k - 2);

        if ((position >= k && k - (position - k + 1) == x) || (position + 1 == x))
        {
            // cout << k << "\n";
            answer++;
        }
    }

    cout << answer << "\n\n";
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