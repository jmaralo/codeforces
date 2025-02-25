#include <bits/stdc++.h>

using namespace std;

void solve(size_t t) {
    size_t n;
    cin >> n;

    vector<pair<int, int>> original(n);
    vector<int> x(n), y(n);
    for (size_t i{0}; i < n; ++i) {
        cin >> x[i] >> y[i];
        original[i] = {x[i], y[i]};
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int x0, y0;
    if ((n % 2) == 0) {
        x0 = x[n / 2];
        y0 = y[n / 2];

        size_t merchant1{0}, merchant2{0}, merchant3{0}, merchant4{0};
        for (size_t i{0}; i < n; ++i) {
            if ((x0 <= original[i].first) && (y0 <= original[i].second)) {
                ++merchant1;
            } else if ((x0 > original[i].first) && (y0 <= original[i].second)) {
                ++merchant2;
            } else if ((x0 <= original[i].first) && (y0 > original[i].second)) {
                ++merchant3;
            } else if ((x0 > original[i].first) && (y0 > original[i].second)) {
                ++merchant4;
            }
        }

        cout << min(min(merchant1, merchant2), min(merchant3, merchant4))
             << "\n";
        cout << x0 << " " << y0 << "\n";

        return;
    } else {
        x0 = x[n / 2];
        y0 = y[n / 2];

        size_t merchant1{0}, merchant2{0}, merchant3{0}, merchant4{0};
        for (size_t i{0}; i < n; ++i) {
            if ((x0 <= original[i].first) && (y0 <= original[i].second)) {
                ++merchant1;
            } else if ((x0 > original[i].first) && (y0 <= original[i].second)) {
                ++merchant2;
            } else if ((x0 <= original[i].first) && (y0 > original[i].second)) {
                ++merchant3;
            } else if ((x0 > original[i].first) && (y0 > original[i].second)) {
                ++merchant4;
            }
        }

        size_t best{min(min(merchant1, merchant2), min(merchant3, merchant4))};
        int best_x0{x0}, best_y0{y0};

        x0 = x[n / 2] + 1;
        y0 = y[n / 2];

        merchant1 = 0, merchant2 = 0, merchant3 = 0, merchant4 = 0;
        for (size_t i{0}; i < n; ++i) {
            if ((x0 <= original[i].first) && (y0 <= original[i].second)) {
                ++merchant1;
            } else if ((x0 > original[i].first) && (y0 <= original[i].second)) {
                ++merchant2;
            } else if ((x0 <= original[i].first) && (y0 > original[i].second)) {
                ++merchant3;
            } else if ((x0 > original[i].first) && (y0 > original[i].second)) {
                ++merchant4;
            }
        }

        if (min(min(merchant1, merchant2), min(merchant3, merchant4)) > best) {
            best = min(min(merchant1, merchant2), min(merchant3, merchant4));
            best_x0 = x0, best_y0 = y0;
        }

        x0 = x[n / 2] + 1;
        y0 = y[n / 2] + 1;

        merchant1 = 0, merchant2 = 0, merchant3 = 0, merchant4 = 0;
        for (size_t i{0}; i < n; ++i) {
            if ((x0 <= original[i].first) && (y0 <= original[i].second)) {
                ++merchant1;
            } else if ((x0 > original[i].first) && (y0 <= original[i].second)) {
                ++merchant2;
            } else if ((x0 <= original[i].first) && (y0 > original[i].second)) {
                ++merchant3;
            } else if ((x0 > original[i].first) && (y0 > original[i].second)) {
                ++merchant4;
            }
        }

        if (min(min(merchant1, merchant2), min(merchant3, merchant4)) > best) {
            best = min(min(merchant1, merchant2), min(merchant3, merchant4));
            best_x0 = x0, best_y0 = y0;
        }

        x0 = x[n / 2];
        y0 = y[n / 2] + 1;

        merchant1 = 0, merchant2 = 0, merchant3 = 0, merchant4 = 0;
        for (size_t i{0}; i < n; ++i) {
            if ((x0 <= original[i].first) && (y0 <= original[i].second)) {
                ++merchant1;
            } else if ((x0 > original[i].first) && (y0 <= original[i].second)) {
                ++merchant2;
            } else if ((x0 <= original[i].first) && (y0 > original[i].second)) {
                ++merchant3;
            } else if ((x0 > original[i].first) && (y0 > original[i].second)) {
                ++merchant4;
            }
        }

        if (min(min(merchant1, merchant2), min(merchant3, merchant4)) > best) {
            best = min(min(merchant1, merchant2), min(merchant3, merchant4));
            best_x0 = x0, best_y0 = y0;
        }

        cout << best << "\n";
        cout << best_x0 << " " << best_y0 << "\n";
    }
}

int main() {
    size_t tt;
    cin >> tt;

    for (size_t t{0}; t < tt; ++t) {
        solve(t);
    }

    return 0;
}