#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
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

int numoffactors(int n){
    int count = 0;
    while(n%2 == 0){
        count++;
        n /= 2;
    }
    for(int i = 3;i <= sqrt(n);i += 2){
        while(n%i == 0){
            count++;
            n /= i;
        }
    }
    if(n > 1)count++;
    return count;
}

const int N = 2e6 + 10;
void solve() {
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    if(c == 1){
        if(a != b && (a%b == 0 || b%a == 0))cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    else{
        int nfa,nfb;
        nfa = numoffactors(a);
        nfb = numoffactors(b);
        if(nfa + nfb >= c)cout<<"Yes\n";
        else cout << "No\n";
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