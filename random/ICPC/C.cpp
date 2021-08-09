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
    ll n, x;
    cin >> n >> x;
    if(n % 2 && x == 0)
        return deb(-1);
    if(x >= n)
        return deb(1);
    int i = 0;
    while(n % (1 << i) <= x)
        i++;
    ll backup = n;
    int oc = 0, ec = 0;
    n -= n % (1 << (i-1));
    for (int i = 0; i < 32;i++){
        if(n & (1 << i)){
            if(i%2)
                oc++;
            else
                ec++;
        }
    }
    int ans1 = oc + ec * 2 + 1;

    n = backup;
    oc = 0, ec = 0;
    for (int i = 0; i < 32;i++){
        if(n & (1 << i)){
            if(i%2)
                oc++;
            else
                ec++;
        }
    }
    int ans2 = oc + ec * 2;

    n = backup - x;
    oc = 0, ec = 0;
    for (int i = 0; i < 32;i++){
        if(n & (1 << i)){
            if(i%2)
                oc++;
            else
                ec++;
        }
    }
    int ans3 = oc + ec * 2 + 1;
    deb(min({ans1, ans2,ans3}));
}

int main() {
#ifndef LOCAL
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}