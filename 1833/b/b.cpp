#include <bits/stdc++.h>

using namespace std;

void solve(int tt) {
    size_t n;
    cin >> n;
    int k;
    cin >> k;

    vector<pair<int, size_t>> forecast(n);
    int expected;
    for (size_t i = 0; i < n; i++) {
        cin >> expected;
        forecast[i] = {expected, i};
    }

    vector<int> actual(n);
    for (size_t i = 0; i < n; i++) {
        cin >> actual[i];
    }

    sort(forecast.begin(), forecast.end());
    sort(actual.begin(), actual.end());

    vector<int> answer(n);
    for (size_t i = 0; i < n; i++) {
        answer[forecast[i].second] = actual[i];
    }

    for (size_t i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

#define TESTCASES true
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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