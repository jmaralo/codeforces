#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

inline ll triang_n(ll n)
{
    return n * (n + 1) / 2;
}

#define TESTCASES true
void solve(ull tt)
{
    size_t n;
    cin >> n;

    vector<ll> lengths(n);
    vector<ll> lengths_ps(n);
    ll ps = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> lengths[i];
        ps += lengths[i];
        lengths_ps[i] = ps;
    }

    ll q;
    cin >> q;

    ll l, u;
    for (ll i = 0; i < q; i++)
    {
        cin >> l >> u;
        ll search = lengths_ps[l - 1] - lengths[l - 1] + u;
        auto find_down = lower_bound(lengths_ps.begin() + l - 1, lengths_ps.end(), search);
        if (find_down == lengths_ps.end())
        {
            cout << n << " ";
            continue;
        }

        ll best_dist = abs(*find_down - search);
        auto best = find_down;

        if (find_down > lengths_ps.begin() + l - 1)
        {
            ll below = abs(*(find_down - 1) - search);
            if (below < best_dist)
            {
                best = (find_down - 1);
                best_dist = below;
            }
        }

        if (find_down + 1 != lengths_ps.end())
        {
            ll above = abs(*(find_down + 1) - search);
            if (above < best_dist)
            {
                best = (find_down + 1);
                best_dist = above;
            }
        }

        cout << best - lengths_ps.begin() + 1 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES)
    {
        solve(0);
        return 0;
    }

    ull t;
    cin >> t;
    for (ull i = 0; i < t; i++)
    {
        solve(i + 1);
    }
    return 0;
}