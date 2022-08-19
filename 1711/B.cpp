#include <bits/stdc++.h>
using namespace std;
// clang-format off
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type> ostream& operator<<(ostream& o, const X& v) { string s; for (const T& x : v) o << s << x, s = " "; return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail> void deb(Head H, Tail... T) { cout << H; if (sizeof...(T) > 0) cout << ' '; deb(T...); }
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif
// clang-format on

void solve() {
    int n,m;
    cin >> n >> m;
    vector<bool> odd(n,0);
    vector<int> unhappiness(n);
    for(int& x : unhappiness) cin >> x;
    vector<unordered_set<int>> graph(n);


    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        graph[a].insert(b);
        graph[b].insert(a);
        odd[a] = !odd[a];
        odd[b] = !odd[b];
    }
    if(m % 2 == 0) return deb(0);

    int min_cost = INT_MAX;
    for(int i = 0;i < n;i++){
        if(odd[i]) min_cost = min(min_cost,unhappiness[i]);
        else{
            for(int x : graph[i]) if(!odd[x]) min_cost = min(min_cost,unhappiness[i] + unhappiness[x]);
        }
    }
    deb(min_cost);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
};