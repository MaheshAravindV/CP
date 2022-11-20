#include <bits/stdc++.h>
using namespace std; using ll = __uint128_t;
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
    ll n,m;
    cin >> n >> m;
    ll bf2 = 1,bf5 = 1;
    while(n%(bf2*2) == 0) bf2 *= 2;
    while(n%(bf5*5) == 0) bf5 *= 5;

    deb(bf2, bf5);
    ll g2 = 1, g5 = 1,ans = 0;
    while(true){
        int temp = max(g2/bf2,(unsigned long long int)1)*max(g5/bf5,(unsigned long long int)1);
        deb(temp);
        if(temp > m) break;
        ans = temp;
        g2 *= 2,g5*= 5;
    }
    if(ans == 0) return deb(n*m);
    deb(n*ans*(m/ans));
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