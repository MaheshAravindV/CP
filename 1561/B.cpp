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
    int a, b;
    cin >> a >> b;
    if(a > b)
        swap(a, b);
    vector<int> ans;
    if((a + b)%2){
        int n2 = (a + b) / 2 + 1;
        int l = b - n2, r = l + 2 * a;
        if(l > r)
            swap(l, r);
        for (int k = l; k <= r;k+=2) ans.push_back(k);
    }
    int n = (a + b)/2;
    int l = b - n, r = l + 2*a;
    if(l > r)
        swap(l, r);
    for (int k = l;k <= r;k+=2)
        ans.push_back(k);
    sort(ans.begin(), ans.end());
    deb(ans.size());
    for (auto& x : ans)
        cout << x << ' ';
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