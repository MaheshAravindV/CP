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
    vector<int> val(26);
    for(int i = 0;i < 26;i++) val[i] = i;
    int i = 0,m = 0;
    while(i < n and val[s[i]-'a'] <= k) m = max(m,s[i]-'a'),i++;
    for(int i = m;i >= 0;i--) val[i] = 0;
    k -= m;

    if(i < n){
        int start = s[i] - k - 'a',end = s[i]-'a';
        for(int i = start;i <= end;i++) val[i] = start;
    }
    for(int i = 0;i < n;i++) cout << (char)(val[s[i]-'a'] + 'a');
    cout << endl;
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