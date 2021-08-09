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
    priority_queue<ll,vector<ll>, greater<>> sizes;
    ll cost = 0;
    for (int i=0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (auto& x : a)
            cin >> x;
        ll l = 1,sum = 0,mx = -1;
        for (int i=1; i < k; i++) {
            if(a[i] < a[i-1]){
                mx = max(mx, l);
                sum += l;
                sizes.push(l);
                l = 0;
            }
            l++;
        }
        mx = max(mx, l);
        sum += l;
        sizes.push(l);
        sum -= mx;
        cost += sum;
    }
    // deb("COST BEFORE MERGE",cost);
    while(sizes.size() > 1){
        ll a = sizes.top();
        sizes.pop();
        ll b = sizes.top();
        sizes.pop();
        // deb("SIZE",a, b);
        cost += a + b;
        sizes.push(a + b);
    }
    deb(cost);
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