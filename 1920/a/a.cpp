#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    int n;
    cin >> n;

    int gt = 0;
    int lt = INT_MAX;
    set<int> eq;
    for (int i = 0; i < n; i++)
    {
        int a, x;
        cin >> a >> x;
        switch (a)
        {
        case 1:
            gt = max(gt, x);
            break;
        case 2:
            lt = min(lt, x);
            break;
        case 3:
            eq.insert(x);
        }
    }

    int count = lt - gt + 1;
    for (auto it = eq.lower_bound(gt); it != eq.upper_bound(lt) && it != eq.end(); it++) {
        count--;
    }

    if (count > 0) {
        cout << count << "\n";
    } else {
        cout << "0\n";
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