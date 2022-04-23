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
    n--;
    int l,r,c;
    cin >> l >> r >> c;
    int left = l,right = r;
    int lcost = c,rcost = 0;
    deb(lcost);
    bool same = true;
    while(n--){
        int l,r,c;
        cin >> l >> r >> c;
        if(l == left and r == right){
            int cost = lcost;
            if(!same) cost += rcost;
            if(cost > c){
                lcost = rcost = c;
                same = true;
                left = l,right = r;
            }
        }
        else if(l <= left and r >= right){
            lcost = rcost = c;
            same = true;
            left = l,right = r;
        }
        else if (l < left and r < right){
            lcost = c;
            left = l;
            same = false;
        }
        else if(l  == left and r < right){
            int cost = lcost;
            if(!same)cost += rcost;
            if(cost > c + rcost){
                left = l;
                lcost = c;
                same = false;
            }
        }
        else if(l > left and r > right){
            rcost = c;
            right = r;
            same = false;
        }
        else if(l > left and r == right){
            int cost = lcost;
            if(!same) cost += rcost;
            if(cost > c + lcost){
                right = r;
                rcost = c;
                same = false;
            }
        }
        if(!same) deb(lcost + rcost);
        else deb(lcost);
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