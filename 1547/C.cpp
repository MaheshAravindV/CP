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
    int k,n,m,x;
    vector<int> ans;
    cin >> k >> n >> m;
    vector<int> a(n),b(m);
    for(int i = 0;i < n;i++){
        cin >> x;
        a[i] = x;
    }
    for(int i = 0;i < m;i++){
        cin >> x;
        b[i] = x;
    }
    int ap = 0,bp = 0;
    for(int i = 0;i < n+m;i++){
        if(ap >= n){
            if(b[bp] > k){
                deb("-1");
                return;
            }
            if(b[bp] == 0) k++;
            ans.push_back(b[bp]);
            bp++;
        }
        else if(bp >= m){
            if(a[ap] > k){
                deb("-1");
                return;
            }
            if(a[ap] == 0) k++;
            ans.push_back(a[ap]);
            ap++;
        }
        else{
            if(a[ap] < b[bp]){
                if(a[ap] > k){
                    deb("-1");
                    return;
                }
                if(a[ap] == 0) k++;
                ans.push_back(a[ap]);
                ap++;
            }
            else{
                if(b[bp] > k){
                    deb("-1");
                    return;
                }
                if(b[bp] == 0) k++;
                ans.push_back(b[bp]);
                bp++;
            }
        }
    }
    for(int c : ans) cout << c << ' ';
    deb();
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