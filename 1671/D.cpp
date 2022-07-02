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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(auto &_ : a) cin >> _;
    ll maxele = *max_element(a.begin(),a.end()),minele = *min_element(a.begin(),a.end());
    ll sum = 0;
    for(int i = 0;i < n-1;i++) sum += abs(a[i+1]-a[i]);
    if(x > maxele and 1 < minele){
        int mi = 0;
        ll d = abs(x-a[0]);
        for(int i = 1;i < n;i++){
            ll nd = abs(x-a[i]) + abs(x-a[i-1]) - abs(a[i]-a[i-1]);
            if(nd < d) d = nd,mi = i;
        }
        if(abs(x-a[n-1]) < d) mi = n;
        a.insert(a.begin()+mi,x);
        ll extra = min(abs(1-a[0]),abs(1-a[n]));
        for(int i = 0;i < n;i++){
            ll t = abs(1-a[i]) + abs(1-a[i+1]) - abs(a[i+1]-a[i]);
            extra = min(extra,t);
        }
        ll ans1 = extra + sum + d;
        // deb(a);
        a.erase(a.begin()+mi);

        mi = 0;
        d = abs(1-a[0]);
        for(int i = 1;i < n;i++){
            ll nd = abs(1-a[i]) + abs(1-a[i-1]) - abs(a[i]-a[i-1]);
            if(nd < d) d = nd,mi = i;
        }
        if(abs(1-a[n-1]) < d) mi = n;
        a.insert(a.begin()+mi,1);
        extra = min(abs(x-a[0]),abs(x-a[n]));
        for(int i = 0;i < n;i++){
            ll t = abs(x-a[i]) + abs(x-a[i+1]) - abs(a[i+1]-a[i]);
            extra = min(extra,t);
        }
        
        ll ans2 = extra + sum + d;
        // deb(a);

        return deb(min(ans1,ans2));
    }
    else if(x > maxele){
        ll extra = min(abs(x-a[0]),abs(x-a[n-1]));
        for(int i = 0;i < n-1;i++){
            ll t = abs(x-a[i]) + abs(x-a[i+1]) - abs(a[i+1]-a[i]);
            extra = min(extra,t);
        }
        return deb(extra + sum);
    }
    else if(1 < minele){
        ll extra = min(abs(1-a[0]),abs(1-a[n-1]));
        for(int i = 0;i < n-1;i++){
            ll t = abs(1-a[i]) + abs(1-a[i+1]) - abs(a[i+1]-a[i]);
            extra = min(extra,t);
        }
        return deb(extra + sum);
    }
    return deb(sum);
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