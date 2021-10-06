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
        int n,p1 = 0,ans = INT_MAX;
        cin >> n;
        vector<int> a(n), b(n),indices(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        for (int i = 0; i < n && p1 < n;i++)
            for (; p1 < b[i] / 2;p1++)
                indices[p1] = i;
        for (int i = 0; i < n;i++)
            ans = min(ans, i + indices[a[i]/2]);
        deb(ans);
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