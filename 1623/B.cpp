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
    vector<pair<int,int>> ranges(n);
    for(auto &_ : ranges) cin >> _.first >> _.second;
    for(int i = 0;i < n;i++){
        if(ranges[i].first == ranges[i].second){
            deb(ranges[i].first,ranges[i].first,ranges[i].first);
            continue;
        }
        int a1 = 0,a2 = n+1;
        for(int j = 0;j < n;j++){
            if(ranges[i].first == ranges[j].first and ranges[i].second > ranges[j].second)
                a1 = max(a1,ranges[j].second+1);
            if(ranges[i].second == ranges[j].second and ranges[i].first < ranges[j].first)
                a2 = min(a2,ranges[j].first-1);
        }
        if(a1 == 0) a1 = a2;
        deb(ranges[i].first,ranges[i].second,a1);
    }
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