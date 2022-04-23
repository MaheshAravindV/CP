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
    vector<pair<int, int>> friends(n);
    for(auto &_ : friends) cin >> _.first >> _.second;
    int l = 0,r = n;
    int ans = 0;
    while(l < r){
        int bl = l,br = r;
        int size = (l+r+1)/2;
        // deb("SIZE : ",size);
        int count = 0;
        for(int i = 0;i < n;i++){
            if(friends[i].first >= size - count - 1 and friends[i].second >= count) count++;
        }
        // deb("COUNT : ",count);
        if(count >= size){
            l = size;
            ans = max(ans,size);
        }
        else
            r = size;
        if(l == bl and r == br) break;
    }
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