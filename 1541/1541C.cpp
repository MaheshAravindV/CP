#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std; using ll = long long;
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

int min(int a,int b){
    if(a < b)return a;
    return b;
}

const int N = 2e6 + 10;
void solve() {
    int n;
    cin >> n;
    ll ans = 0,sum = 0;
    vector<int> l(n);
    for(int i = 0;i < n;i++){
        cin >> l[i];
    }
    if(n <= 2) deb(0);
    else{
        sort(l.begin(),l.end());
        for(int i = 2;i < n;i++)sum += l[i];
        dbg(sum);
        for(int i = 0;i < n-2;i++){
            ans += (n-2-i) * l[i] - sum;
            sum -= l[i+2];
        }
        deb(ans);
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