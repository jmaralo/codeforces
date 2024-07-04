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
    size_t weapons, ingots;
    cin >> weapons >> ingots;

    vector<size_t> ingots_in(weapons);
    for (size_t i = 0; i < weapons; i++) cin >> ingots_in[i];

    vector<size_t> ingots_cost(weapons);
    for (size_t i = 0; i < weapons; i++) {
        cin >> ingots_cost[i];
        ingots_cost[i] = ingots_in[i] - ingots_cost[i];
    }

    vector<size_t> ingot_amount(ingots);
    for (size_t i = 0; i < ingots; i++) cin >> ingot_amount[i];
    priority_queue<size_t> ingot_amount_ordered(ingot_amount.begin(), ingot_amount.end());

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> order;
    for (size_t i = 0; i < weapons; i++) {
        order.push({ingots_cost[i], ingots_in[i]});
    }

    size_t total_weapons = 0;
    while (!order.empty()) {
        pair<size_t, size_t> curr = order.top();
        order.pop();

        while (ingot_amount_ordered.top() >= curr.second) {
            size_t new_amount = ingot_amount_ordered.top();

            if (new_amount > curr.second) {
                size_t consumed = ingot_amount_ordered.top() - curr.second;
                size_t produced = 1 + ((consumed - 1) / curr.first);
                new_amount -= (produced * curr.first);
                total_weapons += produced;
            }

            if (new_amount == curr.second) {
                new_amount -= curr.first;
                total_weapons++;
            }

            ingot_amount_ordered.pop();
            ingot_amount_ordered.push(new_amount);
        }
    }

    cout << total_weapons * 2 << "\n";
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