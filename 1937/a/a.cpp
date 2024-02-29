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

    size_t bits = 0;
    while (n > 0)
    {
        n >>= 1;
        bits++;
    }

    cout << (1 << (bits - 1)) << "\n";
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