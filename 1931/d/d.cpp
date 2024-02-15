#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    size_t n;
    int x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> values(n);
    int value;
    for (size_t i = 0; i < n; i++)
    {
        cin >> value;
        values[i] = {value % x, value % y};
    }
    sort(values.begin(), values.end());

    size_t count = 0;
    for (auto left = values.begin(); left != values.end(); left++)
    {
        pair<int, int> complementary = {(x - left->first) % x, left->second};

        auto first_compl = lower_bound(left + 1, values.end(), complementary);
        auto last_compl = upper_bound(left + 1, values.end(), complementary);
        if (first_compl == values.end())
            continue;

        if (first_compl->first == complementary.first && first_compl->second == complementary.second)
        {
            count += last_compl - first_compl;
        }
    }

    cout << count << "\n";
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