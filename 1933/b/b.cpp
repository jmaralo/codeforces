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
    size_t n;
    cin >> n;

    vector<int> mod_count(3);
    uint element;
    uint sum;
    for (size_t i = 0; i < n; i++)
    {
        cin >> element;
        mod_count[element % 3]++;
        sum += element;
    }
    int answer = abs((mod_count[1] % 3) - (mod_count[2] % 3));
    answer = min(answer, abs(((mod_count[1] - 1) % 3) - ((mod_count[2] + 1) % 3)) + 1);
    answer = min(answer, abs(((mod_count[1] - 1) % 3) - ((mod_count[2]) % 3)) + 1);
    answer = min(answer, abs(((mod_count[1]) % 3) - ((mod_count[2] - 1) % 3)) + 1);
    cout << answer << "\n";
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