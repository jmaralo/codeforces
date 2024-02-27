#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    size_t n;
    cin >> n;

    vector<short> chips(n);
    bool has_chip = false;
    size_t chip_count = 0;
    size_t free_since_last = 0;
    size_t free_between = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> chips[i];
        if (chips[i] == 1)
        {
            has_chip = true;
            chip_count++;
            free_between += free_since_last;
            free_since_last = 0;
        }
        else if (has_chip)
        {
            free_since_last++;
        }
    }

    cout << free_between << "\n";
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