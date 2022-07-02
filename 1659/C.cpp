#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H; if (sizeof...(T) > 0) cout << ' '; deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #_VA_ARGS_ << "]:", deb(_VA_ARGS_)
#else
#define dbg(...)
#endif

const int N = 2e6 + 10;
void solve() {
    int n,a,b;
    cin >> n >> a >> b;
    vector<ll> p(n+1,0),y(n+1,0);
    ll dist = 0;
    for(int i = 1;i <= n;i++) cin >> p[i],dist += p[i];
    for(int i = 0;i < n;i++){
        y[i] = dist;
        dist -= (p[i+1]-p[i]) * (n-i);
    }
    ll ans = INT_FAST64_MAX;
    for(int i = 0;i <= n;i++)
        ans = min(ans,p[i] * (a+b) + b * y[i]);
    deb(ans);
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}