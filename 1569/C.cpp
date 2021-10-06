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
int p = 998244353;
int N = 2e5;
vector<int> facts(N+1);

int lamec(int n,int x){
    return facts[n] / (facts[x] * facts[n - x]);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = -1, sm = -1;
    for (auto& x : a){
        cin >> x;
        if(x > m)
            sm = m,m = x;
        else if(x > sm and x < m)
            sm = x;
    }
    if(sm == -1)
        return deb(facts[n]);
    if(m - sm != 1)
        return deb(0);
    int mcount = 0, smcount = 0;
    for (auto& x : a) {
        if(x == m)
            mcount++;
        if(x == sm)
            smcount++;
    }
    if(mcount > 1)
        return deb(facts[n]);
    int sub = 0;
    for (int i = 0; i < n - smcount;i++)
        sub = (sub+facts[sm + i] * facts[n - smcount - 1 - i]*lamec(n-smcount-1,i)) %p;
    deb(facts[n] - sub);
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    facts[0] = 1;
    for (int i = 1; i < N;i++)
        facts[i] = (facts[i - 1] * i) % p;
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}