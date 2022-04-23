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
        string s;
        cin >> s;
        int zi;
        for (int i = n - 1; i >= 0;i--)
            if(s[i] == '0'){
                zi = i;
                break;
            }
        vector<int> ones,zeroes;
        for (int i = 0; i < zi;i++)
            if(s[i] == '1')
                ones.push_back(i+1);
        for (int i = zi; i >= 0;i--)
            if(s[i] == '0')
                zeroes.push_back(i+1);
        sort(zeroes.begin(), zeroes.end());
        sort(ones.begin(), ones.end());
        vector<int> ans;
        for (auto& x : ones) if(x < zeroes[0])
                ans.push_back(x);
        for (auto& x : zeroes) if(x > ones.back())
                ans.push_back(x);
        if(ans.size() == 0)
            return deb(0);
        deb(1);
        cout << ans.size() << ' ';
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