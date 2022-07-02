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
    int n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(auto &_ : a) cin >> _;
    sort(a.begin(),a.end());
    for(int i = 1;i < n;i++) a[i] += a[i-1];
    ll prev = 0,ans = 0,fans = 0;
    for(int r = n-1;r >= 0;r--){
        ll days = 0;
        if(x >= a[r]) days = 1+(x-a[r])/(r+1);
        ans += (days-prev)*(r+1);
        prev = days;
        fans = max(ans,fans);
    }
    deb(fans);
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