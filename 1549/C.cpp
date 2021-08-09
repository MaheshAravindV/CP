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
    int n,m;
    cin >> n >> m;
    int count[n];
    int ans = 0;
    for (auto& x : count)
        x = 0;
    for (size_t i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u = min(u, v);
        count[u - 1]++;
        if(count[u-1] == 1)
            ans++;
    }

    //for queries
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int u, v;
            cin >> u >> v;
            u = min(u, v);
            count[u - 1]++;
            if(count[u-1] == 1)
                ans++;
        }
        else if(t == 2){
            int u, v;
            cin >> u >> v;
            u = min(u, v);
            count[u - 1]--;
            if(count[u-1] == 0)
                ans--;
        }
        else{
            deb(n - ans);
        }
    }
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}