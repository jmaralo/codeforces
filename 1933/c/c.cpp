#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

#define TESTCASES true
void solve(ull tt)
{
    int a, b, l;
    cin >> a >> b >> l;

    int div_a = 0, div_b = 0;
    int i = l;
    while (i % a == 0)
    {
        div_a++;
        i /= a;
    }
    i = l;
    while (i % b == 0)
    {
        div_b++;
        i /= b;
    }

    unordered_set<int> answers;
    int a_pow = 1;
    for (i = 0; i <= div_a; i++)
    {
        if (l % a_pow != 0)
            break;

        int t = l / a_pow;
        int b_pow = 1;
        for (int j = 0; j <= div_b; j++)
        {
            if (t % b_pow != 0)
                break;

            answers.insert(t / b_pow);
            b_pow *= b;
        }
        a_pow *= a;
    }

    cout << answers.size() << "\n";
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

    ull t;
    cin >> t;
    for (ull i = 0; i < t; i++)
    {
        solve(i + 1);
    }
    return 0;
}