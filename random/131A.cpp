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

const int N = 2e6 + 10;
void solve() {
    string inp;
    cin >> inp;
    bool res = true;
    for(int i = 1;res && i < (int)inp.size();i++)if(inp[i] < 'A' || inp[i] > 'Z')res = false;
    if(!res)deb(inp);
    else{
        if(inp[0] >= 'A' && inp[0] <= 'Z')cout << (char)(inp[0] + 32);
        else cout << (char)(inp[0] - 32);
        for(int i = 1;i < (int)inp.size();i++)cout << (char)(inp[i] + 32);
    }
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}