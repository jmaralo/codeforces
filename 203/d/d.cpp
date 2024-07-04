#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

#define TESTCASES false
void solve(ull tt) {
    double a, b, m;
    cin >> a >> b >> m;

    double vx, vy, vz;
    cin >> vx >> vy >> vz;

    double x0 = abs((a / 2.0) - ((m * vx) / (double)vy));
    double bounces_x = ceil(x0 / a) - 1;
    if ((int)bounces_x % 2 == 0) {
        x0 -= a * bounces_x;
    } else {
        x0 = (a * (bounces_x + 1)) - x0;
    }

    double z0 = abs(-(m * vz) / (double)vy);
    double bounces_z = ceil(z0 / b) - 1;
    if ((int)bounces_z % 2 == 0) {
        z0 -= b * bounces_z;
    } else {
        z0 = (b * (bounces_z + 1)) - z0;
    }

    cout << fixed << setprecision(10) << x0 << " " << z0 << "\n";
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