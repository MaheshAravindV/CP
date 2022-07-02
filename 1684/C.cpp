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
    vector<vector<int>> a(n,vector<int>(m));
    for (auto& row : a) for(auto &_ : row) cin >> _;
    vector<int> index;
    for(int i = 0;i < n;i++){
        vector<int> sorted(m);
        for(int j = 0;j < m;j++)
            sorted[j] = a[i][j];
        sort(sorted.begin(),sorted.end());
        for(int j = 0;j < m;j++)
            if(sorted[j] != a[i][j])
                index.push_back(j);
        if(index.size() > 2) return deb(-1);
        if(index.size() == 2) break;
    }
    if(index.size() == 0) return deb("1 1");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m-1;j++){
            int aj = a[i][j],aj1 = a[i][j+1];
            if(j == index[0]) aj = a[i][index[1]];
            if(j == index[1]) aj = a[i][index[0]];
            if(j+1 == index[0]) aj1 = a[i][index[1]];
            if(j+1 == index[1]) aj1 = a[i][index[0]];
            if(aj > aj1) return deb(-1);
        }
    }
    deb(index[0]+1,index[1]+1);
}
//8 5 6 7 1 8 9 10
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