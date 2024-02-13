#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    size_t n;
    cin >> n;

    set<int> unique_values;
    int value;
    for (size_t i = 0; i < n; i++)
    {
        cin >> value;
        unique_values.insert(value);
    }
    vector<int> values(unique_values.rbegin(), unique_values.rend());
    size_t m = unique_values.size();
    // for (size_t i = 0; i < values.size(); i++)
    // {
    //     cout << values[i] << " ";
    // }
    // cout << "\n";

    size_t left = 0, right = 0;
    size_t answer = 1;
    unordered_set<int> unique;
    while (left < m && right < m)
    {
        int lower_value = values[left] - n;
        while (right < m && values[right] > lower_value)
            right++;

        // cout << left << " " << right << "\n";

        answer = max(answer, right - left);
        left++;
    }

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