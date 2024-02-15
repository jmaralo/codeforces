#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

size_t trailing_zeros(string &s)
{
    size_t zeros = 0;
    for (size_t i = s.size() - 1; i >= 0 && s[i] == '0'; i--)
        zeros++;
    return zeros;
}

void solve(int tt)
{
    size_t n, m;
    cin >> n >> m;

    vector<size_t> trailing(n);
    string num;
    size_t max_length = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> num;
        trailing[i] = trailing_zeros(num);
        max_length += num.size();
    }
    sort(trailing.rbegin(), trailing.rend());

    size_t removed_zeros = 0;
    for (size_t i = 0; i < n; i += 2)
    {
        removed_zeros += trailing[i];
    }

    if (max_length - removed_zeros > m)
        cout << "Sasha\n";
    else
        cout << "Anna\n";
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