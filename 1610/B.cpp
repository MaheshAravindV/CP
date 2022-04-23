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
    vector<int> arr(n);
    for(auto &_ : arr) cin >> _;
    int lp = 0,rp = n-1;
    while(lp < n and rp >= 0 and arr[lp] == arr[rp])
        lp++,rp--;
    if(lp == n and rp == -1) return deb("YES");
    int d1 = arr[lp],d2 = arr[rp];
    int i = lp,j = rp;
    while(i < n and j >= 0 and i != j){
        if(arr[i] == arr[j]) i++,j--;
        else if(arr[i] == d1) i++;
        else if(arr[j] == d1) j--;
        else break;
    }
    if(i >= j) return deb("YES");
    i = lp,j = rp;
    while(i < n and j >= 0 and i != j){
        if(arr[i] == arr[j]) i++,j--;
        else if(arr[i] == d2) i++;
        else if(arr[j] == d2) j--;
        else break;
    }
    if(i >= j) return deb("YES");
    deb("NO");
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