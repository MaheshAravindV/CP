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
    int l,r,x;
    cin >> l >> r >> x;
    int a,b;
    cin >> a >> b;
    if(b == a) return deb(0);
    if(b >= a+x or b <= a-x) return deb(1);
    if((b > a and b+x <= r) or (b < a and b-x >= l)) return deb(2);
    if((b > a and a-x >= l) or (b < a and a+x <= r)) return deb(2);
    if(b > a){
        if(r >= a+x and b-x >= l) return deb(3);
        deb(-1);
    } 
    else{
        if(l <= a-x and b+x <= r) return deb(3);
        deb(-1);
    }
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