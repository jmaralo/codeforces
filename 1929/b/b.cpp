#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    size_t n, k;
    cin >> n >> k;

    size_t twoNeeded = k / 2;
    size_t oneNeeded = k % 2;

    size_t maxTwo = n + n - 2;
    if (twoNeeded > maxTwo)
    {
        oneNeeded += 2 * (twoNeeded - maxTwo);
        twoNeeded = maxTwo;
    }

    cout << twoNeeded + oneNeeded << "\n";
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