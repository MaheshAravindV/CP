#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
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



int n, edges, cnt = 0;
const int N = 2021;
vector<int> tree[N];
vector<int> cur;
vector<bool> vis;

void moo(int start) {
    if (cnt == edges || vis[start]) return;
    vis[start] = 1;
    cout << "? " << start+1 << endl;
    map<int, vector<int>> f;
    for (int i=0; i < n; i++) {
        cin >> cur[i];
        f[cur[i]].push_back(i);
        // if (cur[i] == 1) {
        //     tree[start].push_back(cur[])
        // }
    }
    dbg(f);
    int i=1;
    int root = start;
    do {
        dbg(root);
        for (auto v: f[i]) {
            dbg(v);
            if(!vis[v])tree[root].push_back(v);
            cnt++;
        }
        root = tree[root].back();
    } while (cnt < edges && f[i++].size() == 1);
    dbg(cnt);
    if(cnt == edges)return;
    for(int j = 1;j < i-1;j++)vis[f[j].back()] = 1;
    for (auto v: f[i-1]) moo(v);
}

void solve() {
    cin >> n;
    cur.resize(n);
    vis = vector<bool>(n, false);
    edges = n-1;
    moo(0);
    cout << '!' << endl;
    for(int i = 0;i < n;i++){
        for(int x : tree[i]){
            cout << x+1 << ' ' << i+1 << endl;
        }
    }
}

int main() {
    int T = 1;
    while (T--) solve();
    return 0;
}