#include <bits/stdc++.h>

using namespace std;

typedef unsigned short ushort;
typedef unsigned int uint;

void print_result_excluding(vector<ushort> &digits, size_t excluded_first, size_t excluded_second) {
    size_t n = digits.size();
    bool zero_to_the_left = true;
    for (size_t i = n - 1; i > 0; i--) {
        if (i == excluded_first || i == excluded_second)
            continue;
        
        if (digits[i] == 0 && zero_to_the_left)
            continue;
        
        zero_to_the_left = false;

        cout << digits[i];
    }
    cout << digits[0];
    cout << "\n";
}

void solve(int tt)
{
    size_t n;
    cin >> n;

    vector<ushort> digits(n);
    bool has_zero = false, has_non_zero = false;
    uint digits_sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> digits[i];

        digits_sum += digits[i];
        if (digits[i] == 0)
            has_zero = true;
    }

    if (!has_zero)
    {
        cout << "-1\n";
        return;
    }

    sort(digits.begin(), digits.end());

    uint digits_sum_mod = digits_sum % 3;
    if (digits_sum_mod == 0) {
        print_result_excluding(digits, n, n);
        return;
    }

    size_t single_excluded = n, multi_excluded_first = n, multi_excluded_second = n;
    bool needs_two_excluded = true;
    for (size_t i = 0; i < n; i++)
    {
        if (digits[i] == 0)
            continue;
        else if (digits[i] % 3 == digits_sum_mod) {
            single_excluded = i;
            needs_two_excluded = false;
            break;
        } else if (digits[i] % 3 != 0) {
            if (multi_excluded_first == n) {
                multi_excluded_first = i;
            } else if (multi_excluded_second == n) {
                multi_excluded_second = i;
            }
        }
    }

    if (needs_two_excluded) {
        if (multi_excluded_first == n || multi_excluded_second == n) {
            cout << "-1\n";
            return;
        } else {
            print_result_excluding(digits, multi_excluded_first, multi_excluded_second);
            return;
        }
    } else {
        print_result_excluding(digits, single_excluded, n);
        return;
    }
}

#define TESTCASES false
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