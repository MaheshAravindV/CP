#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
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

const int N = 2e6 + 10;
void solve() {
    int n,s,t;
    if(n == 1){
        deb("1");
        return;
    }
    set<int> x;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t;
        xs += t;
        x.insert(t);
        cin >> t;
        ys += t;
        y.insert(t);
    }
    deb("OP");
    if(x.find(xs/n) == x.end())
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