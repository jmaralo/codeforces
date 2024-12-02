#include <bits/stdc++.h>

using namespace std;

typedef signed char byte;
typedef unsigned char ubyte;

typedef unsigned short ushort;

typedef unsigned int uint;

typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;

constexpr ull coins[5]{1, 3, 6, 10, 15};

template <unsigned long long M, typename T = long long>
class Mod {
   private:
    T value{};

   public:
    Mod() = default;
    Mod(T initial) : value(initial) {}

    Mod<M, T>& operator=(const Mod<M, T>& other) {
        if (this == &other) return *this;

        value = other.value;
        return *this;
    }

    Mod<M, T>& operator++() {
        value = (value + 1) % M;
        return *this;
    }

    Mod<M, T> operator++(int) {
        Mod<M, T> old = *this;
        operator++();
        return old;
    }

    Mod<M, T>& operator--() {
        value = (value - 1) % M;
        return *this;
    }

    Mod<M, T> operator--(int) {
        Mod<M, T> old = *this;
        operator++();
        return old;
    }

    Mod<M, T>& operator+=(const Mod<M, T>& rhs) {
        value = (value + rhs->value) % M;
        return *this;
    }

    Mod<M, T>& operator+=(const T& rhs) {
        value = (value + (rhs % M)) % M;
    }
};

#define TESTCASES true
void solve(ull tt) {
    ull target;
    cin >> target;

    ull result{0};
    for (int i = 4; i >= 0; i--) {
        result += target / coins[i];
        target %= coins[i];
    }

    cout << result << "\n";
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