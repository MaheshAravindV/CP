#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << "," << p.second << ')';
}
template <typename X,
          typename T = typename enable_if<!is_same<X, string>::value,
                                          typename X::value_type>::type>
ostream &operator<<(ostream &o, const X &v) {
    o << '{';
    string s;
    for (const T &x : v) o << s << x, s = " ";
    return o << '}';
}
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>
void deb(Head H, Tail... T) {
    cout << H << ' ';
    deb(T...);
}
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define nl "\n"
#define FOR(i, a, n) for (ll i = a; i <= n; i++)
#define ROF(i, a, n) for (ll i = a; i >= n; i--)
#define all(x) ((x).begin() + 1, (x).end())
#define vall(x, n) (x) + 1, (x) + n + 1
#define All(x) ((x).begin(), (x).end())
#define Vall(x, n) (x), (x) + n
const int N = 2e6 + 10;

int n, k[N], c[N], m;
void solve() {
    int x;
    cin >> x;
    deb((x+1)/10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}