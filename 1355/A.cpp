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

ll f(ll n){
    ll m = 9,M = 0;
    while(n){
        m = min(m,n%10);
        M = max(M,n%10);
        n /= 10;
    }
    return m*M;
}

const int N = 2e6 + 10;
void solve() {
    ll a,k;
    cin >> a >> k;
    k--;
    while(k--){
        int t = f(a);
        if(t == 0) return deb(a);
        a += t;
    }
    deb(a);
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