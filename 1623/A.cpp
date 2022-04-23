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
    int n,m,rb,cb,rd,cd,t = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dx = 1,dy = 1;
    while(true){
        if(rb == rd or cb == cd) break;
        if(rb+dy == 0 or rb+dy == n+1){
            dy *= -1;
            continue;
        }
        if(cb+dx == 0 or cb+dx == m+1){
            dx *= -1;
            continue;
        }
        rb += dy;
        cb += dx;
        t++;
    }
    deb(t);
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