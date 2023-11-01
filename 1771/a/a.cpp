#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, long long int> c;
    int mx = INT_MIN, mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        c[a[i]]++;
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    if (mn == mx)
        cout << (c[mn] - 1) * c[mn] << "\n";
    else
        cout << 2 * (c[mx] * c[mn]) << "\n";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve(i);
    }
    return 0;
}