#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    size_t n;
    cin >> n;

    vector<size_t> values(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    size_t begin_eq = 1;
    while (begin_eq < n && values[begin_eq] == values[begin_eq - 1])
        begin_eq++;

    size_t end_eq = n - 1;
    while (end_eq > 0 && values[end_eq] == values[end_eq - 1])
    {
        end_eq--;
    }

    if (begin_eq > end_eq)
    {
        cout << "0\n";
        return;
    }

    if (values[begin_eq - 1] != values[end_eq])
    {
        cout << min(n - begin_eq, end_eq) << "\n";
    }
    else
    {
        cout << end_eq - begin_eq << "\n";
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