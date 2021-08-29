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
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    if(a[n-1] == 0){
        for (int i = 1; i <= n+1;i++)
            cout << i << ' ';
        return deb();
    }
    if(a[0] == 1){
        cout << n + 1 << ' ';
        for (int i = 1; i <= n;i++)
            cout << i << ' ';
        return deb();
    }
    int flag = 0;
    for (int i = 0; i < n-1;i++){
        if(a[i] == 0 && a[i+1] == 1){
            flag = 1;
            for (int j = 1; j <= i+1;j++)
                cout << j << ' ';
            cout << n + 1 << ' ';
            for (int j = i + 2; j <= n;j++)
                cout << j << ' ';
            return deb();
        }
    }
    if(!flag)
        deb(-1);
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