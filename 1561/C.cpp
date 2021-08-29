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
const ll INF = 0x7f7f7f7f7f7f7f7f;
const int inf = 0x7f7f7f7f;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    int total = 0;
    for(int p = 0;p < n;p++){
        int ki;
        cin >> ki;
        total += ki;
        int maxval = 0;
        for (int i = 0; i < ki;i++){
            int x;
            cin >> x;
            maxval = max(maxval, x + 1 - i);
        }
        a.push_back({maxval,ki});
    }
    sort(a.begin(),a.end());
    int fans = 0,taken = 0;
    for (int i = 0; i < n;i++){
        fans = max(fans, a[i].first - taken);
        taken += a[i].second;
    }
    deb(fans);
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