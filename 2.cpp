#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i < (n); ++i)
#define fornn(i, n) for (int i = 0; i <= (n); ++i)
#define forn1n(i, n) for (int i = 1; i <= (n); ++i)
#define each(x, a) for (auto& x : a)
#define eachp(x, y, a) for (auto& [x, y] : a)
#define pb push_back
#define F first
#define S second

using ll = long long;
using ull = unsigned long long;
using vb = vector<char>;
using vvb = vector<vector<char>>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using str = string;
using pi = array<int, 2>;
using pll = array<ll, 2>;
using vpi = vector<pi>;
using vpll = vector<pll>;
using gr = vector<vector<pll>>;

namespace ra = std::ranges;
namespace rv = std::ranges::views;

template <int MOD>
struct ModInt;

template <int MOD>
ModInt<MOD> bin_pow(ModInt<MOD> a, ll n) {
    ModInt<MOD> res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

template <int MOD>
inline ModInt<MOD> inv(ModInt<MOD> a) {
    return bin_pow<MOD>(a, MOD - 2);
}

template <int MOD>
struct ModInt {
    int x;

    ModInt() noexcept : x(0) {}

    ModInt(int n) noexcept : x(n % MOD) {}

    inline ModInt& operator+=(ModInt other) noexcept {
        x += other.x;
        x %= MOD;
        return *this;
    }

    inline ModInt operator+(ModInt other) noexcept {
        ModInt res(x);
        res += other;
        return res;
    }

    inline ModInt& operator++() noexcept {
        *this += 1;
        return *this;
    }

    inline ModInt operator++(int) noexcept {
        ModInt temp = *this;
        ++(*this);
        return temp;
    }

    inline ModInt& operator-=(ModInt other) noexcept {
        *this += MOD - other.x;
        return *this;
    }

    inline ModInt operator-(ModInt other) noexcept {
        ModInt res(x);
        res -= other;
        return res;
    }

    inline ModInt& operator*=(ModInt other) noexcept {
        x = (x * 1ll * other.x) % MOD;
        return *this;
    }

    inline ModInt operator*(ModInt other) noexcept {
        ModInt res(x);
        res *= other;
        return res;
    }

    inline ModInt& operator/=(ModInt other) noexcept {
        *this *= inv<MOD>(other);
        return *this;
    }

    inline ModInt operator/(ModInt other) noexcept {
        ModInt res(x);
        res /= other;
        return res;
    }

    friend ostream& operator<<(ostream& os, ModInt mi) {
        os << mi.x;
        return os;
    };
};

template <int MOD, int N>
struct Fact {
    using mi = ModInt<MOD>;
    array<mi, N> fact;

    Fact() noexcept {
        fact[0] = mi(1);
        for (int i = 1; i < N; i++) {
            fact[i] = fact[i - 1] * mi(i);
        }
    }

    inline mi C(int n, int k) {
        if (k > n) {
            return 0;
        }
        return fact[n] / (fact[n - k] * fact[k]);
    }
};

constexpr int N = 1e6;

constexpr int MOD = 1e9 + 7;

using mi = ModInt<MOD>;

Fact<MOD, N + 1> fact;

void solve() {
    int n;
    cin >> n;
    int ch = n / 2, nch = n - (n / 2);
    cout << fact.C(ch, 3) + fact.C(nch, 2) * ch << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
