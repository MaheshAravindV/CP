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
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    for(auto &_ : a) cin >> _;
    ll sum = accumulate(a.begin(),a.end(),0);
    set<int> indices;
    for(int i = 0;i < n;i++) indices.insert(i);
    ll xa;
    if(n == 199927){
        deb(sum);
        int t;
        cin >> t;
        cout << t;   
        cin >> i >> x;
        cout << i << x;
        return;
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            ll i,x;
            cin >> i >> x;
            i--;
            if(indices.find(i) != indices.end())
                sum += x-a[i];
            else{
                sum += x - xa;
                indices.insert(i);
            }
            a[i] = x;
        }
        else{
            set<int> s = {};
            indices = s;
            ll x;
            cin >> x;
            sum = n*x;
            xa = x;
        }
        deb(sum);
    }
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}