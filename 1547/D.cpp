#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; using ll = long long; using ld = long double;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H << ' ', deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define int ll

const int N = 2e6 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0;i < n;i++){
        cin >> l[i];
    }
    if(n == 1){
        deb(0);
        return;
    }
    vector<int> ob(30,0);
    int i = 0;
    while(l[0]){
        ob[i] = l[0] %2;
        l[0] /= 2;
        i++;
    }
    cout << 0 << ' ';
    for(i = 1;i < n;i++){
        int tba = 1;
        int ans = 0;
        for(int j = 0;j < 30;j++){
            int b1 = ob[j];
            int b2 = l[i] %2;
            if(b1 && !b2) ans += tba;
            if(b2) ob[j] = 1;
            tba *= 2;
            l[i] /= 2;
        }
        cout << ans << ' ';
    }
    deb();
}

int32_t main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}