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

const int N = 2e6 + 10;
void solve() {
    int n,a,b;
    cin >> n >> a >> b;
    int zg = 0,og = 0;
    string inp;
    cin >> inp;
    if(b >= 0){
        deb(n*(a+b));
        return;
    } 
    for (int i=1; i < n; i++) {
        if(inp[i] != inp[i-1]){
            if(inp[i-1] == '0')zg++;
            else og++;
        }
    }
    if(inp[n-1] == '0')zg++;
    else og++;
    deb(n*a + (min(og,zg)+1)*b);
}

int32_t main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}