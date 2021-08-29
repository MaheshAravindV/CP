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
    int n, q;
    cin >> n >> q;
    string in;
    cin >> in;
    vector<int> countp(n+1),countn(n+1);
    for (int i = 0; i < n;i++){
        countp[i+1] = countp[i], countn[i+1] = countn[i];
        int x = (in[i] == '+') ? 1 : -1;
        if(i%2) x *= -1;
        (x == 1) ? countp[i+1]++ : countn[i+1]++;
    }
    deb(countp);
    deb(countn);
    for (int i = 0; i < q;i++){
        int l, r;
        cin >> l >> r;
        deb(abs((countp[r] - countp[l - 1]) - (countn[r] - countn[l - 1])));
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