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
    int m;
    cin >> m;
    int a[2][m];
    for (int i = 0; i < m;i++)
        cin >> a[0][i];
    for (int i = 0; i < m;i++)
        cin >> a[1][i];
    if(m == 1)
        return deb(0);
    for (int i = 1; i < m;i++)
        a[0][i] = a[0][i - 1] + a[0][i], a[1][i] = a[1][i - 1] + a[1][i];
    int res = min(a[0][m - 1] - a[0][0], a[1][m - 2]);
    for (int i = 1; i < m - 1;i++){
        res = min(res, max(a[0][m - 1] - a[0][i], a[1][i-1]));
    }
    deb(res);
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