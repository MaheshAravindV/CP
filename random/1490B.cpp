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
    int n,c0 = 0,c1 = 0,c2 = 0;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if(x % 3 == 0)
            c0++;
        else if(x%3 == 1)
            c1++;
        else
            c2++;
    }
    int res = 0;
    int d = max(0, c0 - n / 3);
    c0 -= d;
    c1 += d;
    res += d;
    d = max(0, c1 - n / 3);
    c1 -= d;
    c2 += d;
    res += d;
    d = max(0, c2 - n / 3);
    c2 -= d;
    c0 += d;
    res += d;
    d = max(0, c0 - n / 3);
    res += d;
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