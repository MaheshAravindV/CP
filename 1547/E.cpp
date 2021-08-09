#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; using ll = long long; using ld = long double;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H << ' ', deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define int ll

const int N = 2e6 + 10;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<pair <int,int>> ac(k);
    vector<int> ai(k),t(k);
    for(int i = 0;i < k;i++) cin >> ai[i];
    for(int i = 0;i < k;i++) cin >> t[i];
    if(k == 1){
        for(int i = 0;i < n;i++) cout << abs(ai[0] - 1 - i) + t[0] << ' ';
        deb();
    }
    else{
        for(int i = 0;i < k;i++) ac[i] = make_pair(ai[i]-1,t[i]);
        sort(ac.begin(),ac.end());
        for(int i = 0;i < ac[0].first;i++)cout << ac[0].first-i + ac[0].second << ' ';
        int acc = 0;
        for(int i = ac[0].first;i <= ac.back().first;i++){
            int x = min(i-ac[acc].first+ac[acc].second,ac[acc+1].first-i+ac[acc+1].second);
            cout << x << ' ';
            if(acc+1 < k && i == ac[acc+1].first) acc++;
        }
        for(int i = ac.back().first+1;i < n;i++) cout << i - ac.back().first + ac.back().second << ' ';
        deb();
    }       
}

int32_t main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}