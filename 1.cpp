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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<ll, 4>>> gr(n);
    forn(i, m) {
        ll a, b, t, r, g;
        cin >> a >> b >> t >> r >> g;
        a--;
        b--;
        gr[a].pb({b, t, r, g});
    }
    int s = 0;
    vll d(n, 1e12);
    d[s] = 0;
    priority_queue<pll, vpll, greater<pll>> q;
    q.push({0, s});
    auto wait = [&](ll t, ll r, ll g) -> ll {
        ll d = r + g;
        t %= d;
        // 0 1 2 3 4 5 6
        // _____
        if (t >= r) {
            return 0ll;
        }
        return r - t;
    };
    while (!q.empty()) {
        auto [cur_d, v] = q.top();
        q.pop();
        if (cur_d > d[v]) {
            continue;
        }
        for (auto [u, t, r, g] : gr[v]) {
            if (d[u] > d[v] + t + wait(d[v], r, g)) {
                d[u] = d[v] + t + wait(d[v], r, g);
                q.push({d[u], u});
            }
        }
    }
    cout << d[n - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
