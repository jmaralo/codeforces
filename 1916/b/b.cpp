#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

void solve(int tt)
{
    ull a, b;
    cin >> a >> b;

    unordered_map<ull, ull> fa;
    ull at = a;
    for (ull i = 2; i < at; i++)
    {
        while (at % i == 0)
        {
            at /= i;
            fa[i]++;
        }
    }
    if (at > 1)
        fa[at]++;

    unordered_map<ull, ull> fb;
    ull bt = b;
    for (ull i = 2; i < bt; i++)
    {
        while (bt % i == 0)
        {
            bt /= i;
            fb[i]++;
        }
    }
    if (bt > 1)
        fb[bt]++;

    ull p = 1;
        cout << "a:\n";
    for (auto [n, c]: fa) {
        cout << n << " " << c << "\n";
        if (fb.count(n)) {
            p *= max(fb[n] - c, ull(1));
        } else {
            p *= c;
        }
    }

    cout << "b:\n";
    for (auto [n, c]: fb) {
        cout << n << " " << c << "\n";
    }

    cout << p * b << "\n";
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