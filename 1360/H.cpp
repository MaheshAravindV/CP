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

ll toInt(string s){
    ll res = 0;
    for(int i = 0;i < s.size();i++){
        res *= 2;
        res += s[i] - '0';
    }
    return res;
}

const int N = 2e6 + 10;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<ll> rem(n);
    string s;
    for(int i = 0;i < n;i++){
        cin >> s;
        rem[i] = toInt(s);
    }
    sort(rem.begin(),rem.end());
    ll median = (pow(2,m) - rem.size()-1)/2;
    int offset,error = 0;
    while(median < pow(2,m)){
        int offset = upper_bound(rem.begin(),rem.end(),median) - rem.begin() - error;
        median += offset;
        error += offset;
        if(!offset) break;
    }
    for(int i = m-1;i >= 0;i--) (median & (1LL << i)) ? cout << 1 : cout << 0;
    deb();
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