#include <vector>
#include <iostream>
using namespace std; using ll = long long;
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

int max(int a,int b){
    if(a < b)return b;
    return a;
}

int min(int a,int b){
    if(a > b)return b;
    return a;
}

int min(int a,int b,int c,int d){
    return min(min(min(a,b),c),d);
}

const int N = 0;
void solve() {
    int n,mi,m = -1,Mi,M = -1,t;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t;
        if(t < m || m == -1){
            mi = i;
            m = t;
        }
        if(t > M || M == -1){
            Mi = i;
            M = t;
        }
    }
    int a1 = max(mi,Mi)+1;
    int a2 = n- min(mi,Mi);
    int a3 = mi + 1 + n - Mi;
    int a4 = Mi + 1 + n - mi;
    cout << min(a1,a2,a3,a4) << '\n';
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