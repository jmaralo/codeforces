#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

bool starts_with(string s, string prefix) {
    return s.rfind(prefix, 0) == 0;
}

#define TESTCASES false
void solve(ull tt) {
    size_t l;
    cin >> l;

    string command;
    stack<pair<uint32_t, size_t>> result;
    result.push({0, 1});
    for (size_t i = 0; i < l; i++) {
        cin >> command;

        if (command == "for") {
            size_t amount;
            cin >> amount;
            result.push({0, amount});
        } else if (command == "end") {
            auto [sum, repeated] = result.top();
            result.pop();
            if (sum > UINT32_MAX / repeated || result.top().first > UINT32_MAX - (sum * repeated)) {
                cout << "OVERFLOW!!!\n";
                return;
            }
            result.top().first += sum * repeated;
        } else if (command == "add") {
            if (result.top().first >= UINT32_MAX) {
                cout << "OVERFLOW!!!\n";
                return;
            }

            result.top().first++;
        }
    }

    cout << result.top().first << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!TESTCASES) {
        solve(0);
        return 0;
    }

    ull t;
    cin >> t;
    for (ull i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}