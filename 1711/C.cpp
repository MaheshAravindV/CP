#include <bits/stdc++.h>
using namespace std;
// clang-format off
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type> ostream& operator<<(ostream& o, const X& v) { string s; for (const T& x : v) o << s << x, s = " "; return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail> void deb(Head H, Tail... T) { cout << H; if (sizeof...(T) > 0) cout << ' '; deb(T...); }
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif
// clang-format on
int t = 0;
#define ll long long
void solve() {
    t++;
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    for(ll& x : a) cin >> x;

    bool rflag = false,cflag = false;
    for(ll x : a){
        if(x >= 3 * n) cflag = true;
        if(x >= 3 * m) rflag = true;
        if(x >= n * m) return deb("Yes");
    }
    ll rcount = 0,ccount = 0;
    for(ll x : a){
        if(x >= 2 * m) rcount += x/m;
        if(x >= 2 * n) ccount += x/n;
    }
    
    if( ((n%2 == 0 or rflag) and rcount >= n) or ((m%2 == 0 or cflag) and ccount >= m)) return deb("Yes");
    deb("No");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}