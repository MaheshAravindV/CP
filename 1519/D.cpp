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
    vector<ll> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    
    vector<ll> prefpdt(n+1,0);
    for (int i =0; i < n;i++)
        prefpdt[i+1] = prefpdt[i] + a[i]*b[i];

    ll ans = prefpdt[n];
    for (int c = 0; c < n;c++){
        int pdt = a[c] * b[c];
        int l = c - 1, r = c + 1;
        while(l >= 0 && r < n){
            pdt += a[l] * b[r] + a[r] * b[l];
            ans = max(ans, pdt + prefpdt[l] + prefpdt[n] - prefpdt[r + 1]);
            l--, r++;
        }
        pdt = 0;
        l = c, r = c + 1;
        while(l >= 0 && r < n){
            pdt += a[l] * b[r] + a[r] * b[l];
            ans = max(ans, pdt + prefpdt[l] + prefpdt[n] - prefpdt[r + 1]);
            l--, r++;
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
    // cin >> T;
    while (T--) solve();
    return 0;
}