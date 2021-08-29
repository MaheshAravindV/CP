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
const ll INF = 0x7f7f7f7f7f7f7f7f;
const int inf = 0x7f7f7f7f;
const int N = 2e6 + 10;
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if(n == 2)
        return deb(x, y);
    pair<int, int> min = {-1,-1};
    for (int gap = 1; gap <= n;gap++){
        int d = (y - x) / gap;
        if((y-x)%gap || (y - (n-1)*d) > x || (x + gap*d) < y)
            continue;
        int a = max(x - (((x-1) / d) * d),y - (n-1)*d);
        // deb(a,d,a+(n-1)*d);
        if(a + n * d < min.first + n * min.second or min.first == -1)
            min.first = a, min.second = d;
    }
    for (int i = 0; i < n;i++){
        cout << min.first + i * min.second << ' ';
    }
    deb();
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