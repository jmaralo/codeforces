#include <bits/stdc++.h>

using namespace std;

#define TESTCASES false
void solve(int tt) {
    int n;
    cin >> n;

    string f;
    cin >> f;

    unordered_map<char, int> count;
    for (int i = 0; i < n; i++)
        count[f[i]]++;

    int i = 0;
    while (i < n) {
        count[f[i]]--;
        if (count[f[i]] <= 0) {
            count[f[i]]++;
            break;
        }
        i++;
    }

    int j = n - 1;
    while (j >= 0) {
        count[f[j]]--;
        if (count[f[j]] <= 0) {
            count[f[j]]++;
            break;
        }
        j--;
    }

    cout << j - i + 1 << "\n";
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