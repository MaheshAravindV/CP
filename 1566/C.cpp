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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> taken(n, 0);
    int ans = 0;
    for (int i = 0; i < n;i++)if(a[i] != b[i])
            taken[i] = 1,ans += 2;
    for (int i = 0; i < n;i++){
        if(taken[i])
            continue;
        if(a[i] == '0' && b[i] == '0'){
            taken[i] = 1, ans++;
            if(i > 0 && !taken[i-1] && a[i-1] == '1' && b[i-1] == '1')
                taken[i - 1] = 1, ans++;
            else if(i < n-1 && !taken[i+1] && a[i+1] == '1' && b[i+1] == '1')
                taken[i + 1] = 1, ans++;
        }
    }
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