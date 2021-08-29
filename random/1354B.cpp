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
    string in;
    cin >> in;
    int n = in.length();
    vector<vector<int>> indices(3);
    int minans = inf;
    for (int i = 0; i < n;i++) indices[in[i] - '1'].push_back(i);
    for (int i = 0; i < n;i++){
        vector<int> ni(3);
        int f = 0;
        for (int j = 0; j < 3;j++){
            auto it = lower_bound(indices[j].begin(), indices[j].end(), i);
            if(it != indices[j].end())
                ni[j] = *it;
            else
                f = 1;
        }
        if(f)
            continue;
        int ans = *max_element(ni.begin(), ni.end())-i+1;
        minans = min(minans, ans);
    }
    deb(minans == inf ? 0 : minans);
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