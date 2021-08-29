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

int cost(string& x,string& n){
    int np = 0,cost = 0;
    for (int i = 0; i < x.length();i++){
        while(np < n.length() && n[np] != x[i])
            np++, cost++;
        if(np >= n.length())
            cost += x.length() - i;
    }
    cost += n.length() - np;
    return cost;
}
vector<string> powers = {"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288","1048576","2097152","4194304","8388608","16777216","33554432","67108864","134217728","268435456","536870912"};
// vector<string> powers = {"65536"};
const int N = 2e6 + 10;
void solve() {
    string n;
    cin >> n;
    int mincost = 10000;
    for (auto& x : powers) {
        mincost = min(mincost, cost(x, n));
    }
    deb(mincost);
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