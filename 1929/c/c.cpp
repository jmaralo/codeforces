#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve(int tt)
{
    ull ratio, max_losses;
    ull initial_coins;
    cin >> ratio >> max_losses >> initial_coins;

    ull coins = initial_coins;
    for (size_t i = 0; i < max_losses; i++)
    {
        ull bet = 1 + (initial_coins - coins) / (ratio - 1);
        if (coins < bet)
        {
            cout << "NO\n";
            return;
        }
        coins -= bet;
    }

    if (coins + (coins * (ratio - 1)) <= initial_coins)
    {
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