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
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto& x : h)
        cin >> x;
    vector<ll> sums(n - k+1);
    for (int i = 0; i < k;i++)
        sums[0] += h[i];
    for (int i = 1; i < n - k + 1;i++)
        sums[i] = sums[i-1] + h[i + k - 1] - h[i - 1];
    int min = -1;
    for (int i = 0; i < n - k + 1;i++)
        if(min == -1 or sums[i] < sums[min])
            min = i;
    deb(min+1);
}
int main(){
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}