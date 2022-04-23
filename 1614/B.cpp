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
    ll n, cost = 0;
    cin >> n;
    vector<pair<ll,ll>> freq(n);
    for (int i = 0; i < n;i++)
        cin >> freq[i].first, freq[i].second = i+1;
    sort(freq.begin(), freq.end(),greater<pair<ll,ll>>());
    vector<pair<ll, ll>> res = {{0,0}};
    ll m = 0;
    for (auto& x : freq){
        if(res.size() % 2)
            res.push_back({x.second,res.back().second * -1 + 1});
        else
            res.push_back({x.second,res.back().second * -1});
        cost += abs(res.back().second) * 2  * x.first;
    }
    sort(res.begin(), res.end());
    deb(cost);
    for (auto& x : res)
        cout << x.second << ' ';
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