#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << p.first << ' ' << p.second; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H; if (sizeof...(T) > 0) cout << ' '; deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #_VA_ARGS_ << "]:", deb(_VA_ARGS_)
#else
#define dbg(...)
#endif

const int N = 2e6 + 10;
vector<map<int, int>> forest(2);

int find(int t,int k){
    if(forest[t][k] == k)
        return k;
    return forest[t][k] = find(t,forest[t][k]);
}

void sunion(int t,int a,int b){
    int x = find(t, a);
    int y = find(t, b);
    forest[t][x] = y;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 0; i < n;i++)
        forest[0][i] = i, forest[1][i] = i;
    set<pair<int, int>> edges;
    int flag = 0;
    while(m1--){
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        edges.insert({a,b});
        if(find(0,a) == find(0,b))
            flag = 1;
        sunion(0, a, b);
    }
    while(m2--){
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        edges.insert({a, b});
        if(find(1,a) == find(1,b))
            flag = 1;
        sunion(1, a, b);
    }
    if(flag)
        return deb(0);
    int addedge = 0;
    vector<pair<int, int>> resedge;
    for (int a = 1; a < n;a++){
        for (int b = a+1; b <= n;b++){
            if(edges.find({a,b}) == edges.end()){
                if(!(find(1,a) == find(1,b) || find(0,a) == find(0,b))){
                    addedge++;
                    sunion(0, a, b);
                    sunion(1, a, b);
                    resedge.push_back({a, b});
                }
            }
        }
    }
    deb(addedge);
    for (auto& x : resedge)
        deb(x);
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