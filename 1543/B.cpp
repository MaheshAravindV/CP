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
#define int ll

int inp(){
    int x;
    cin >> x;
    return x;
}

const int N = 2e6 + 10;
void solve() {
    int n,sum = 0;
    cin >> n;
    for (int i=0; i < n; i++) {
        sum += inp();
    }
    deb(sum%n * (n - sum%n));
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