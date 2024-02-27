#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    long long n, k;
    cin >> n >> k;

    vector<pair<long long, long long>> monsters(n, {0, 0});
    long long health;
    for (long long i = 0; i < n; i++)
    {
        cin >> health;
        monsters[i].second = health;
    }

    int position;
    for (size_t i = 0; i < n; i++)
    {
        cin >> position;
        monsters[i].first = abs(position);
    }
    sort(monsters.begin(), monsters.end());

    long long time = 0;
    long long fire_power = 0;
    for (long long i = 0; i < n; i++)
    {
        long long delta_time = monsters[i].first - time;

        fire_power += delta_time * k;
        if (fire_power < monsters[i].second)
        {
            cout << "NO\n";
            return;
        }
        fire_power -= monsters[i].second;

        time = monsters[i].first;
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