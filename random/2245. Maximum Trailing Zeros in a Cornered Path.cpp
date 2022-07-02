#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H; if (sizeof...(T) > 0) cout << ' '; deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #VA_ARGS << "]:", deb(VA_ARGS)
#else
#define dbg(...)
#endif

const int N = 2e6 + 10;

int factcnt(int n,int base){
    int ans = 0;
    while(n%base == 0) ans++,n /= base;
    return ans;
}


int maxTrailingZeros(vector<vector<int>>& grid) {
    int m = grid.size(),n = grid[0].size();
    vector<vector<ll>> twos(m+1,vector<ll>(n+1,0)),fives(m+1,vector<ll>(n+1,0));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            int curr = factcnt(grid[i-1][j-1],2);
            int a1 = 0,a2 = 0,a3 = 0;
            a1 = twos[i-1][j];
            a2 = twos[i][j-1];
            a3 = twos[i-1][j-1];
            twos[i][j] = a1 + a2 - a3 + curr;

            curr = factcnt(grid[i-1][j-1],5);
            a1 = 0,a2 = 0,a3 = 0;
            a1 = fives[i-1][j];
            a2 = fives[i][j-1];
            a3 = fives[i-1][j-1];
            fives[i][j] = a1 + a2 - a3 + curr;
        }
    }

    int ans = 0;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            int ans1 = min(twos[i][j] - twos[i-1][j-1],fives[i][j] - fives[i-1][j-1]);
            int ans2 = min(twos[i][n] - twos[i][j-1] - (twos[i-1][n] - twos[i-1][j]),fives[i][n] - fives[i][j-1] - (fives[i-1][n] - fives[i-1][j]));
            int ans3 = min(twos[m][j] - twos[i-1][j] - (twos[m][j-1] - twos[i][j-1]),fives[m][j] - fives[i-1][j] - (fives[m][j-1] - fives[i][j-1]));
            int ans4 = min(twos[m][n] - twos[i-1][n] - twos[m][j-1] + twos[i-1][j-1] - (twos[m][n] - twos[i][n] - twos[m][j] + twos[i][j]),fives[m][n] - fives[i-1][n] - fives[m][j-1] + fives[i-1][j-1] - (fives[m][n] - fives[i][n] - fives[m][j] + fives[i][j]));
            ans = max({ans,ans1,ans2,ans3,ans4});
        }
    }
    return ans;
}

void solve() {
    vector<vector<int>> grid = {{4,3,2},{7,6,1},{8,8,8}};
    cout << maxTrailingZeros(grid);
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