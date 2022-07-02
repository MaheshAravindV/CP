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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    string potans;
    int spt = 0,fpt = 0;
    bool flag = 0;
    for(;fpt < min(n,k);){
        if(s[fpt] < s[spt]) fpt++,deb("TEST");
        else if(s[fpt] == s[0]){
            flag = true;
            spt = 0;
            potans = s.substr(0,fpt);
            deb(potans);
        }
        else break;
        if(flag) spt++;
    }
    potans = s.substr(0,fpt);
    deb(potans);
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