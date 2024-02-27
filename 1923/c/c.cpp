#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve(int tt)
{
    size_t n, q;
    cin >> n >> q;

    vector<ull> numbers(n);
    vector<ull> prefix_sum(n, 0), prefix_sum_min(n, 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> numbers[i];
        prefix_sum[i] += numbers[i];
        prefix_sum_min[i] += numbers[i] == 1 ? 2 : 1;
        if (i > 0)
        {
            prefix_sum[i] += prefix_sum[i - 1];
            prefix_sum_min[i] += prefix_sum_min[i - 1];
        }
    }

    size_t left, right;
    for (size_t i = 0; i < q; i++)
    {
        cin >> left >> right;

        if (left == right)
        {
            cout << "NO\n";
            continue;
        }

        ull sum = prefix_sum[right - 1] - prefix_sum[left - 1] + numbers[left - 1];
        ull min_sum = prefix_sum_min[right - 1] - prefix_sum_min[left - 1] + (numbers[left - 1] == 1 ? 2 : 1);

        if (min_sum > sum)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
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