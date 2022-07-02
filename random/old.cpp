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
    vector<vector<ll>> twos(m,vector<ll>(n,0)),fives(m,vector<ll>(n,0)),tens(m+1,vector<ll>(n+1,0));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            int curr = factcnt(grid[i][j],2);
            int a1 = 0,a2 = 0,a3 = 0;
            if(i > 0) a1 = twos[i-1][j];
            if(j > 0) a2 = twos[i][j-1];
            if(i > 0 and j > 0) a3 = twos[i-1][j-1];
            twos[i][j] = a1 + a2 - a3 + curr;

            curr = factcnt(grid[i][j],5);
            a1 = 0,a2 = 0,a3 = 0;
            if(i > 0) a1 = fives[i-1][j];
            if(j > 0) a2 = fives[i][j-1];
            if(i > 0 and j > 0) a3 = fives[i-1][j-1];
            fives[i][j] = a1 + a2 - a3 + curr;

            tens[i+1][j+1] = min(fives[i][j],twos[i][j]);
        }
    }

    for (auto& row : twos) deb(row);
    deb();
    for (auto& row : fives) deb(row);
    deb();
    for (auto& row : tens) deb(row);

    int ans = 0;
    // for(int i = 1;i <= 1;i++){
    //     for(int j = 3;j <= 3;j++){
    //         // int ans1 = tens[i][j] - tens[i-1][j-1];
    //         // int ans2 = tens[i][n] - tens[i][j-1] - (tens[i-1][n] - tens[i-1][j]);
    //         // int ans3 = tens[m][j] - tens[i-1][j] - (tens[m][j-1] - tens[i][j-1]);
    //         int ans4 = tens[m][n] - tens[i-1][n] - tens[m][j-1] + tens[i-1][j-1] - (tens[m][n] - tens[i][n] - tens[m][j] + tens[i][j]);
    //         deb(tens[m][n] - tens[i-1][n] - tens[m][j-1] + tens[i-1][j-1]);
    //         deb((tens[m][n] - tens[i][n] - tens[m][j] + tens[i][j]));
    //         // deb("(",i,j,") ->",ans1,ans2,ans3,ans4);
    //     }
    // }
    return ans;
}

void solve() {
    vector<vector<int>> grid = {{23,17,15,3,20},{8,1,20,27,11},{9,4,6,2,21},{40,9,1,10,6},{22,7,4,5,3}};
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