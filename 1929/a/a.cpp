#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

void solve(int tt)
{
    size_t n;
    cin >> n;

    vector<uint> values(n);
    for (size_t i = 0; i < n; i++)
        cin >> values[i];

    sort(values.begin(), values.end());

    uint answer = 0;
    for (size_t i = 1; i < n; i++)
        answer += values[i] - values[i - 1];

    cout << answer << "\n";
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