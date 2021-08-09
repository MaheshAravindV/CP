#include <vector>
#include <iostream>
#include <algorithm>
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
 
const int N = 2e6 + 10;
void solve() {
    int n,l,r;
    cin >> n;
    cin >> l;
    cin >> r;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)cin >> arr[i];
    sort(arr.begin(),arr.end());
    ll pc = 0;
    for(int i = 0;i < n-1;i++){
        int le = l - arr[i];
        int re = r - arr[i];
        int li,ri;
        li = lower_bound(arr.begin()+i+1,arr.end(),le) - arr.begin();
        ri = upper_bound(arr.begin()+i+1,arr.end(),re) - arr.begin();
        if(li <= ri)pc += (ri-li);
    }
    cout << pc << '\n';
    n = 2+3-4;//random shit
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