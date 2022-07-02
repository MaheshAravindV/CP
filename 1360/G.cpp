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
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(m*b != a*n) return deb("NO");

    deb("YES");
    for(int offset = 0;offset < m;offset++){
        vector<vector<bool>> grid(n,vector<bool>(m,0));
        vector<int> colsum(m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < a;j++){
                grid[i][(j+offset*i)%m] = 1;
                colsum[(j+offset*i)%m]++;
            }
        }
        // deb("COLSUM",colsum);
        bool sol = true;
        for (auto& x : colsum) if(x != b){sol = false;break;}
        if(sol){
            for (auto& row : grid){
                for (auto val : row) cout << val;
                deb();
            }
            break;
        }            
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