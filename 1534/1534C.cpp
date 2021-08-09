#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std; using ll = long long;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H << ' ', deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif
int n;
const int N = 4e5 + 10;
vector<int> g[N];
bool used[N] ;
ll numcomp = 0;
void dfs(int v) {
    dbg(v);
    used[v] = true ;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void find_comps() {
    for (int i = 1; i <= n ; ++i)
        used [i] = false;
    for (int i = 1; i <= n ; ++i)
        if (!used[i]) {
            numcomp++;
            dfs(i);
        }
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    vector<int> l1(n),l2(n);
    for(int i = 0;i < n;i++)cin >> l1[i];
    for(int i = 0;i < n;i++)cin >> l2[i];
    for(int i = 0;i < n;i++)g[l1[i]].push_back(l2[i]);
    find_comps();
    deb(binpow(2,numcomp,1e9+7));
    numcomp = 0;
    for(int i = 1;i <= n;i++){
        dbg(g[i]);
        g[i].clear();
    }
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