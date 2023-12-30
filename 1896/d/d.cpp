#include <bits/stdc++.h>

using namespace std;

void solve(int tt)
{
    int n, q;
    cin >> n >> q;

    vector<unsigned short> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> ps(n);
    ps[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        ps[i] = ps[i - 1] + a[i];
    }

    long long s;
    int j;
    unsigned short v;
    bool f = false;
    for (int i = 0; i < q; i++)
    {
        unsigned short op;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> s;
            for (int k = n - 1; k >= 0 && ps[k] > s; k--)
            {
                if (binary_search(ps.begin(), ps.end(), ps[k] - s))
                {
                    cout << "YES\n";
                    f = true;
                    break;
                }
            }
            if (ps[n - 1] == s)
            {
                cout << "YES\n";
                f = true;
            }
            
            if (!f)
            {
                cout << "NO\n";
            }
            f = false;
            break;
        case 2:
            cin >> j >> v;
            j -= 1;
            long long diff = v - a[j];
            a[j] = v;
            if (diff == 0)
                goto stop_2;
            for (int k = j; k < n; k++)
            {
                ps[k] += diff;
            }
        stop_2:
            break;
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