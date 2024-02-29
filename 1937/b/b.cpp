#include <bits/stdc++.h>

using namespace std;

typedef signed char schar;
typedef unsigned char uchar;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

enum rows
{
    TOP,
    DOWN,
};

#define TESTCASES true
void solve(ull tt)
{
    size_t n;
    cin >> n;

    string top;
    string down;
    cin >> top >> down;

    size_t ambiguous_start = -1, ambiguous_end = -1;
    size_t i;
    for (i = 0; i < n - 1; i++)
    {
        if (top[i + 1] == down[i])
        {
            ambiguous_start = i;
            if (ambiguous_end == -1)
                ambiguous_end = i;
        }
        else if (down[i] == '0')
            break;
        else
        {
            ambiguous_start = -1;
            ambiguous_end = -1;
        }
    }

    string mn = top.substr(0, i + 1) + down.substr(i);

    size_t count = ambiguous_start - ambiguous_end + 2;
    if (ambiguous_start == -1)
        count = 1;

    cout
        << mn << "\n"
        << count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout << 200000 << "\n";
    // for (size_t i = 0; i < 200000; i++)
    // {
    //     cout << '0';
    // }
    // cout << "\n";
    // for (size_t i = 1; i < 200000; i++)
    // {
    //     cout << '0';
    // }
    // cout << "\n";
    // exit(0);

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