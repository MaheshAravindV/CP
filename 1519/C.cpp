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
    int n,mu = 0;
    cin >> n;
    vector<int> u(n),s(n);
    for (auto& x : u)
        cin >> x,mu = max(mu,x);
    for (auto& x : s)
        cin >> x;
    vector<vector<ll>> univsum(mu);
    for (int i = 0; i < n;i++)
        univsum[u[i] - 1].push_back(s[i]);
    for (auto& x : univsum)
        sort(x.begin(), x.end(),greater<int>());
    for (auto& x : univsum)
        for (int i = 1; i < x.size(); i++)
            x[i] += x[i - 1];
    vector<ll> regionsum(n);
    for (auto& x : univsum) {
        for (int k = 1; k <= x.size();k++){
            if (x.size() / k == 0)
                continue;
            int index = (x.size() / k) * k - 1;
            regionsum[k-1] += x[index];
        }   
    }
    for (auto& x : regionsum)
        cout << x << ' ';
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