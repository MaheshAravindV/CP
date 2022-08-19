#include <bits/stdc++.h>
using namespace std;
// clang-format off
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type> ostream& operator<<(ostream& o, const X& v) { string s; for (const T& x : v) o << s << x, s = " "; return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail> void deb(Head H, Tail... T) { cout << H; if (sizeof...(T) > 0) cout << ' '; deb(T...); }
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif
// clang-format on

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s;
    for(int i = 0;i < n;i++){
        string x = "";
        cin >> x;
        if(t.find(x) != t.npos) s.push_back(x);
    }

    n = s.size();
    vector<vector<pair<int,int>>> g(n);
    
    for(int i = 0;i < n;i++){
        string s1 = s[i];
        for(int j = 0;j < n;j++){
            if(i == j) continue;
            string s2 = s[j];
            for(int k = 0;k < s1.size();k++){
                if(k + s2.size() <= s1.size()) continue;
                bool take = true;
                for(int l = k;l < s1.size() and take;l++) if(s1[l] != s2[l-k]) take = false;
                if(take) g[i].push_back({k,j});
            }
        }
    }

    for(int i = 0;i < n;i++) deb(i,g[i]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}