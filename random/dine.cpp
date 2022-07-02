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

class Solution {
public:
    int count(int n, int x) {
        int count = 0;
        while (n % x == 0 and n > 0) n /= x,count += 1;
        return count;
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> hor5(m, vector<int>(n)), hor2(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hor5[i][j] = count(grid[i][j], 5) + (j > 0 ? hor5[i][j - 1] : 0);
                hor2[i][j] = count(grid[i][j], 2) + (j > 0 ? hor2[i][j - 1] : 0);
                
            }
        }
        
        vector<vector<int>> ver5(m, vector<int>(n)), ver2(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                ver5[i][j] = count(grid[i][j], 5) + (i > 0 ? ver5[i - 1][j] : 0);
                ver2[i][j] = count(grid[i][j], 2) + (i > 0 ? ver2[i - 1][j] : 0);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int right2 = hor2[i][n - 1] - hor2[i][j];
                int right5 = hor5[i][n - 1] - hor5[i][j];
                int top2 = i > 0 ? ver2[i - 1][j] : 0;
                int top5 = i > 0 ? ver5[i - 1][j] : 0;
                int left2 = j > 0 ? hor2[i][j - 1] : 0;
                int left5 = j > 0 ? hor5[i][j - 1] : 0;
                int bot2 = ver2[m - 1][j] - ver2[i][j];
                int bot5 = ver5[m - 1][j] - ver5[i][j];
                int cur2 = count(grid[i][j], 2);
                int cur5 = count(grid[i][j], 5);
                
                // topright
                int twos = right2 + top2 + cur2;
                int five = right5 + top5 + cur5;
                
                ans = max(ans, min(twos, five));
                    
                // topleft
                twos = left2 + top2 + cur2;
                five = left5 + top5 + cur5;
                
                ans = max(ans, min(twos, five));
                    
                // botright
                twos = right2 + bot2 + cur2;
                five = right5 + bot5 + cur5;
                
                ans = max(ans, min(twos, five));
                    
                // botleft
                twos = left2 + bot2 + cur2;
                five = left5 + bot5 + cur5;
                
                ans = max(ans, min(twos, five));
                    
            }
        }
        return ans;
    }
};