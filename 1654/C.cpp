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
    ll n,t,sum = 0;
    cin >> n;
    unordered_multiset<ll> a,need;
    while(n--){
        cin >> t;
        sum += t;
        a.insert(t);
    }
    // deb(sum);
    need.insert(sum);
    while(a.size() > 0 and need.size() <= a.size()){
        ll x = *need.begin();
        if(a.find(x) != a.end()){
            a.erase(a.find(x));
            need.erase(need.find(x));
        }
        else{
            need.erase(need.find(x));
            need.insert(x/2);
            need.insert((x+1)/2);
        }
    }
    
    if(a.size() == 0) return deb("YES");
    deb("NO");
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