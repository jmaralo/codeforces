#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pxor(n + 1);
    pxor[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        pxor[i] = pxor[i - 1] ^ a[i - 1];
    }

    string s;
    cin >> s;

    int o = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            o ^= a[i];
        }
        else
        {
            z ^= a[i];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int r;
        cin >> r;
        switch (r)
        {
        case 1:
            int l, r;
            cin >> l >> r;
            o ^= pxor[l - 1] ^ pxor[r];
            z ^= pxor[l - 1] ^ pxor[r];
            break;
        case 2:
            int g;
            cin >> g;
            if (g)
            {
                cout << o << " ";
            }
            else
            {
                cout << z << " ";
            }
            break;
        }
    }

    cout << "\n";
}

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