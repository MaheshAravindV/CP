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

bool group(int x){
    x = x%10;
    if(x == 1 or x == 2 or x == 4 or x == 8) return 1;
    else return 0;
}

bool fives(int x) {
    if(x % 10 == 5 or x % 10 == 0) return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;

    for (auto& x : a) if(fives(x) != fives(a[0])) return deb("No");

    if(fives(a[0])){
        int target = a[0] + a[0]%10;
        for (auto& x : a) {
            x += x%10;
            if(x != target) return deb("No");
        }
        return deb("Yes");
    }
    
    bool orgcycle = (group(a[0]) == (a[0]/10)%2 == 0);

    // deb(orgcycle);

    for (auto& x : a) {
        if((group(x) == (x/10)%2 == 0) != orgcycle) return deb("No");
    }
    deb("Yes");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}