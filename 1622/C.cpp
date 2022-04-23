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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &_ : a) cin >> _;
    sort(a.begin(),a.end());
    // deb(a);
    ll sum = 0;
    ll ans = INT_MAX;
    for(int m = 0;m < n;m++){
        if(m > 0) sum += a[m];
        ll t = a[0] - floor(((k-sum)*1.0)/(n-m));
        // deb("How much to dec",t);
        ans = min(n-m-1+max(t,0LL),ans);
        // deb(m,ans);
        if(ans <= 0) break;
    }
    deb(max(0LL,ans));
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