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
    if(n == 1)
        return deb(1);
    if(n == 2)
        return deb(-1);
    if(n == 3)
        return deb("2 9 7\n4 6 3\n1 8 5");
    if(n%2){
        int line[n];
        for (int i = 0; i < n;i++){
            line[i] = i / 2 + 1;
            if(i%2)
                line[i] += n * (n / 2 + 1);
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cout << line[j] << ' ';
                line[j] += n / 2;
                if(j%2 == 0)
                    line[j] += 1;
            }
            deb();
        }
    }
    else{
        int line[n];
        for (int i = 0; i < n;i++){
            line[i] = i / 2 + 1;
            if(i%2)
                line[i] += (n * n) / 2;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n;j++){
                cout << line[j] << ' ';
                line[j] += n / 2;
            }
            deb();
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