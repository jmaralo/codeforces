#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

bool is_subsequence(string a, string b) {
    if (a.length() > b.length())
        return false;

    size_t ptr_a = 0, ptr_b = 0;
    while (ptr_a < a.size() && ptr_b < b.size()) {
        if (a[ptr_a] == b[ptr_b]) {
            ptr_a++;
            ptr_b++;
        } else {
            ptr_b++;
        }
    }

    return ptr_a == a.size();
}

#define TESTCASES true
void solve(ull tt) {
    string a;
    cin >> a;

    string b;
    cin >> b;

    size_t min_length = min(a.length(), b.length());
    for (size_t i = 0; i < min_length; i++) {
        size_t window_size = min_length - i;
        for (size_t j = 0; j <= b.size() - window_size; j++) {
            if (is_subsequence(b.substr(j, window_size), a)) {
                cout << a.length() + (b.length() - window_size) << "\n";
                return;
            }
        }
    }

    cout << a.length() + b.length() << "\n";
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