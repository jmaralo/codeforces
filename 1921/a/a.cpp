#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    int x3, y3;
    cin >> x3 >> y3;
    int x4, y4;
    cin >> x4 >> y4;

    cout << (max(max(x1, x2), max(x3, x4)) - min(min(x1, x2), min(x3, x4))) * (max(max(y1, y2), max(y3, y4)) - min(min(y1, y2), min(y3, y4))) << "\n";
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