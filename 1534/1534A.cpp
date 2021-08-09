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
    int n,m;
    cin >> n;
    cin >> m;
    bool f = true;
    string row;
    char cii = '_';
    for(int i = 0;i < n;i++){
        cin >> row;
        for(int j = 0;j < m;j++){
            if(row[j] != '.'){
                if(cii == '_'){
                    cii = row[j];
                    if(i%2 != j%2){
                        if(cii == 'R')cii = 'W';
                        else cii = 'R';
                    }
                }
                else{
                    if(i%2 == j%2){
                        if(row[j] != cii){
                            f = false;
                            break;
                        }
                    }
                    else{
                        if(row[j] == cii){
                            f = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(!f){
        deb("NO");
        return;
    }
    deb("YES");
    if(cii == '_')cii = 'R';
    char notc = cii == 'R'?'W':'R';
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i%2 != j%2)cout << notc;
            else cout << cii;
        }
        cout << '\n';
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