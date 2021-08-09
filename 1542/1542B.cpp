#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std; using ll = long long;
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

int sol(int n,int a,int b){
    dbg(n,a,b);
    if(n < 1) return 0;
    if(n == 1) return 1;
    if(n%a == 0) return sol(n/a,a,b) | sol(n-b,a,b);
    else return sol(n-b,a,b);
    return 0;
}

const int N = 2e6 + 10;
void solve() {
    int n,a,b;
    cin >> n;
    cin >> a;
    cin >> b;
    if(a == 1){
        if((n-1)%b) deb("NO");
        else deb("YES");
        return;
    }
    if(sol(n,a,b)) deb("YES");
    else deb("NO");
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