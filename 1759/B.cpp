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
    int m,s;
    cin >> m >> s;
    vector<int> b(m);
    for(auto &_ : b) cin >> _;

    int su = 0, M = 0;
    for (auto& x : b){
        su -= x;
        M = max(M, x);
    } 
    su += (M*(M+1))/2;
    s -= su;
    int i = M;
    while(1){
        if((i*(i+1))/2 - (M*(M+1))/2 > s) return deb("NO");
        if((i*(i+1))/2 - (M*(M+1))/2 == s) return deb("YES");
        i++;
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