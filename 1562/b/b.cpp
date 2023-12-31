#include <bits/stdc++.h>

using namespace std;

#define TESTCASES true
void solve(int tt, bool composite[100]) {
    long k;
    std::cin >> k;
    std::string s;
    std::cin >> s;

    int res(0);
    for (long p = 0; p < s.size(); p++) {
        if (s[p] == '1' || s[p] == '4' || s[p] == '6' || s[p] == '8' || s[p] == '9') {
            res = s[p] - '0';
        }
    }

    if (res) {
        std::cout << 1 << std::endl
                  << res << std::endl;
        return;
    }

    for (long p = 0; !res && p < s.size(); p++) {
        for (long q = p + 1; !res && q < s.size(); q++) {
            long x = 10 * (s[p] - '0') + (s[q] - '0');
            if (composite[x]) {
                res = x;
            }
        }
    }

    std::cout << 2 << std::endl
              << res << std::endl;
}

int main() {
    bool composite[100] = {0};
    composite[1] = true;
    for (long p = 2; p < 11; p++) {
        if (composite[p]) {
            continue;
        }
        for (long q = 2 * p; q < 100; q += p) {
            composite[q] = 1;
        }
    }

    if (!TESTCASES) {
        solve(0, composite);
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1, composite);
    }
    return 0;
}