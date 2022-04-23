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
vector<int> sevens;
int diff(int a,int b){
    int res = 0;
    while(a | b){
        if(a % 10 != b % 10) res++;
        a /= 10,b /= 10;
    }
    return res;
}
int len(int a){
    int l = 0;
    while(a) l++,a /= 10;
    return l;
}

const int N = 2e6 + 10;
void solve() {
    int n;
    cin >> n;
    pair<int,int> ans = {10,0};
    int l = len(n);
    for(auto c : sevens)
        if(len(c) == l and diff(c,n) < ans.first) ans.first = diff(c,n),ans.second = c;
    deb(ans.second);
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    for(int i = 14;i <= 999;i+=7) sevens.push_back(i);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}