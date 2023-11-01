#include <bits/stdc++.h>

using namespace std;

int convert(string raw, int radix) {
    int res = 0, n = raw.size();
    for (int i = n - 1; i >= 0; i--) {
        if (raw[i] >= '0' && raw[i] <= '9') {
            res += (raw[i] - '0') * pow(radix, n - i - 1);
        } else {
            res += (10 + raw[i] - 'A') * pow(radix, n - i - 1);
        }
    }
    return res;
}

string revert(int val, int radix) {
    string res = "";
    while (val > 0) {
        int m = val % radix;
        if (m < 10) {
            res = char('0' + m) + res;
        } else {
            res = char('A' + m - 10) + res;
        }
        val /= radix;
    }
    return res;
}

#define TESTCASES false
void solve(int tt) {
    int n, radix;
    cin >> n >> radix;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        int val = convert(num, radix);
        sum += val;
    }

    cout << revert(sum, radix) << "\n";
}

int main() {
    if (!TESTCASES) {
        solve(0);
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}