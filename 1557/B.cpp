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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    if(n == 1)
        return deb("Yes");

    vector<int> sorted(n);
    for (int i = 0; i < n;i++)
        sorted[i] = a[i];
    sort(sorted.begin(),sorted.end());
    k--;
    map<int, int> m;
    for (int i = 1; i < n;i++)
        m[sorted[i]] = sorted[i - 1];
    for (int i = 1; i < n; i++)
    {
        if (a[i] == sorted[0] || a[i - 1] != m[a[i]])
            k--;
        if (k < 0)
            return deb("No");
    }
    deb("Yes");
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