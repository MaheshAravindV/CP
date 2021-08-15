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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> t(n);
    vector<int> ls(n), rs(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : t)
        cin >> x;
    for (int i = 0; i < n;i++)
        t[i] = max(0, t[i]);
    if(n == 1)
        return deb(max(0,a[0] + k * t[0]));
    ls[0] = max(0, a[0]);
    rs[n - 1] = max(0,a[n - 1]);
    for (int i = 1; i < n-1;i++){
        ls[i] = ls[i - 1] + a[i];
        ls[i] = max(0, ls[i]);
    }
    for (int i = n - 2; i > 0;i--){
        rs[i] = rs[i + 1] + a[i];
        rs[i] = max(0, rs[i]);
    }
    int res = max({a[0] + t[0] * k + rs[1], a[n - 1] + t[n - 1] * k + ls[n-2],0});
    // deb(res);
    for (int i = 1; i < n-1;i++) res = max(res,a[i] + t[i] * k + ls[i-1] + rs[i+1]);
    // deb(ls);
    // deb(rs);
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