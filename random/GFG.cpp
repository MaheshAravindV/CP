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
string makeEven(string s)
    {
        int n = s.length();
        if((s[n-1]-'0')%2){
            int min = -1;
            for(int i = 0;i < n-1;i++){
                if ((s[i] - '0') % 2 == 0)
                {
                    if (s[i] < s[n - 1])
                    {
                        min = i;
                        break;
                    }
                    else min = i;
               }
            }
            if(min != -1){
                char c = s[min];
                s[min] = s[n-1];
                s[n-1] = c;
            }
            return s;
        }
        return s;
    }
    
const int N = 2e6 + 10;
void solve() {
    deb(makeEven("4543"));
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