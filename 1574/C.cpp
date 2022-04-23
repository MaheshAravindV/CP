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
    ll sumv(vector<ll> a){
        ll sum = 0;
        for (auto& x : a)
            sum += x;
        return sum;
    }

    const int N = 2e6 + 10;
    void solve() {
        ll n,zero = 0;
        cin >> n;
        vector<ll> h(n);
        for (auto& x : h)
            cin >> x;
        sort(h.begin(), h.end());
        ll sum = sumv(h);
        int d;
        cin >> d;
        for (int i = 0; i < d;i++){
            ll x, y,cost = 0;
            cin >> x >> y;
            int index = lower_bound(h.begin(), h.end(), x) - h.begin();
            if(index == n){
                cost = x - h[n - 1] + max(zero,y - sum + h[n-1]);
            }
            else if(h[0] > x){
                cost = max(zero, y - sum + h[0]);
            }
            else if(h[index] != x){
                ll c1 = max(zero,y - sum + h[index]);
                ll c2 = x - h[index - 1] + max(zero, y - sum + h[index - 1]);
                // deb(index);
                // deb(c1, c2);
                cost = min(c1, c2);
            }
            else{
                cost = max(zero, y - sum + h[index]);
            }
            deb(cost);
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