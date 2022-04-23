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
    int n,M;
    cin >> n;
    vector<int> a(n);
    for(auto &_ : a) cin >> _;
    vector<int> mexsuffix(n);
    vector<bool> visited(n,false);
    int mex = 0;
    for(int i = n-1;i >= 0;i--){
        if(a[i] < n) visited[a[i]] = 1;
        while(visited[mex]) mex++;
        mexsuffix[i] = mex;
    }
    int p = 0;
    fill(visited.begin(), visited.end(),false);
    mex = 0;
    vector<int> ans;
    while(p < n){
        for(int j = p;j < n;j++){
            if(a[j] < n) visited[a[j]] = 1;
            while(mex < n and visited[mex]) mex++;
            if(mex == mexsuffix[p]){
                ans.push_back(mex);
                mex = 0;
                fill(visited.begin(), visited.end(),false);
                p = j+1;
                break;
            }
        }
    }
    deb(ans.size());
    deb(ans);
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