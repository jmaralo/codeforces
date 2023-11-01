#include <bits/stdc++.h>

using namespace std;

double dist(double ax, double ay, double bx, double by) {
    return sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by)));
}

#define TESTCASES true
void solve(int tt) {
    double px, py;
    cin >> px >> py;

    double ax, ay;
    cin >> ax >> ay;

    double bx, by;
    cin >> bx >> by;

    double a0 = dist(ax, ay, 0, 0), b0 = dist(bx, by, 0, 0);
    double ap = dist(ax, ay, px, py), bp = dist(bx, by, px, py);
    double ab = dist(ax, ay, bx, by);
    if (a0 <= b0 && ap <= bp) {
        cout << max(a0, ap) << "\n"; 
    } else if (b0 <= a0 && bp <= ap) {
        cout << max(b0, bp) << "\n";
    } else if (a0 <= b0 && bp <= ap) {
        cout << max(max(a0, bp), ab / 2.0) << "\n";
    } else if (b0 <= a0 && ap <= bp) {
        cout << max(max(b0, ap), ab / 2.0) << "\n";
    } else {
        cout << "0\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(11);

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