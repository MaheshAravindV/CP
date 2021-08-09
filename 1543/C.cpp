#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; using ll = long long; using ld = long double;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H << ' ', deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define int ll
ld max(ld a,ld b){
    if(a > b) return a;
    return b;
}

ld expected(ld c,ld m,ld p,ld v,int depth = 1){
    ld md = min(m,v),cd = min(c,v);
    dbg(c,m,cd,md,v);
    if(c < 1e-9 && m < 1e-9) return depth;
    else if(c < 1e-9 && m > 1e-9)
        return depth * p + m * expected(0,m-md,p+md,v,depth+1);
    else if(c > 1e-9 && m < 1e-9)
        return depth * p + c * expected(c - cd,0,p + cd,v,depth+1);
    else{
        return depth * p + c * expected(c-cd,m + cd/2,p + cd/2,v,depth+1) + m * expected(c + md/2,m-md,p + md/2,v,depth+1);    
    }
        
}

const int N = 2e6 + 10;
void solve() {
    ld c,m,p,v;
    cin >> c >> m >> p >> v;
    deb(expected(c,m,p,v));
}

int32_t main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    cout << setprecision(6) << fixed;
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}