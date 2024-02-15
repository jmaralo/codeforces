#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    unsigned short n;
    cin >> n;

    if (n <= 28)
    {
        cout << "aa" << (char)('a' + n - 3) << "\n";
    }
    else if (n <= 53)
    {
        cout << "a" << (char)('a' + n - 28) << "z\n";
    }
    else
    {
        cout << (char)('a' + n - 53) << "zz\n";
    }
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