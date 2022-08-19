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

void solve() {
    int n,H,M,ans = 24*60;
    cin >> n >> H >> M;
    M += H*60;
    bool done = false;
    while(n--){
        int h,m;
        cin >> h >> m;
        m += h*60;
        if(m == M) done = true;
        if(m > M) ans = min(ans,m-M);
        else ans = min(ans,24*60+m-M);
    }
    if(done) return deb("0 0");
    deb(ans/60,ans%60);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}