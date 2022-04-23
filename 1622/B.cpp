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
    vector<int> p(n);
    for(auto &_ : p) cin >> _;
    vector<pair<int, int>> liked,disliked;
    string input;
    cin >> input;
    for(int i = 0;i < n;i++){
        if(input[i] == '0') disliked.push_back({p[i],i});
        else liked.push_back({p[i],i});
    }
    sort(liked.begin(), liked.end());
    sort(disliked.begin(), disliked.end());
    vector<int> ans(n);
    int i = 1;
    for (auto& x : disliked)
        ans[x.second] = i++;
    for (auto& x : liked) 
        ans[x.second] = i++;
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