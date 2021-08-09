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
    int a[] =  {465, 55, 3, 54, 234, 12, 45, 78};
    int n = 8;
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            int M = 0;
            for (int k = i; k <= j;k++)
                M = max(M, a[k]);
            for (int m = 2; m <= M;m++){
                int mod = a[i] % m;
                int sol = 1;
                for (int k = i+1; sol && k <= j;k++){
                    if (a[k]%m != mod)
                        sol = 0;
                }
                if(sol){
                    deb(i, j, "M = ",m);
                    for (int k = i; k <= j;k++)
                        cout << a[k] << ',';
                    deb();
                    m = M + 1;
                }
            }
        }
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