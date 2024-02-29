#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

#define TESTCASES true
void solve(ull tt)
{
    size_t n;
    cin >> n;

    vector<uint> values(n);
    for (size_t i = 0; i < n; i++)
        cin >> values[i];

    sort(values.begin(), values.end());

    if (values[0] != values[1])
    {
        cout << "YES\n";
        return;
    }
    else if (values[0] == 1)
    {
        cout << "NO\n";
        return;
    }

    for (size_t i = 2; i < n; i++)
    {
        if (values[i] % values[0] != 0)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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