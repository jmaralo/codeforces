#include <bits/stdc++.h>

using namespace std;

vector<int> get_div(int n)
{
    int s = sqrt(n);
    vector<int> div;
    for (int i = 2; i <= s; i++)
        if (n % i)
            div.push_back(i);

    return div;
}

void solve(int tt)
{
    int n;
    cin >> n;
    vector<int> k = get_div(n);

    vector<int> a(n);
    vector<vector<int>> divs(n);
    int sz = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        divs[i] = get_div(a[i]);
        sz = max(sz, int(divs[i].size()));
    }

    for (auto it = k.begin(); it != k.end(); it++) {
        for (int i = 0; i < *it; i++) {
            vector<int> intersec(sz);
            auto end = set_intersection(divs[i].begin(), divs[i].end(), divs[i + *it].begin(), divs[i + *it].end(), intersec.begin());
            for (int j = i + *it + *it; j < n; j += *it) {

            }
        }
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