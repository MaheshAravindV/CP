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
    vector<vector<int>> board;
    int n,m;

    int gridColor(int x,int y){
        if(x >= 0 and x < n-1 and y >= 0 and y < m-1){
            return max({board[x][y],board[x+1][y],board[x][y+1],board[x+1][y+1]});
        }
        return -1;
    }

    bool isGrid(int x,int y){
        if(x >= 0 and x < n-1 and y >= 0 and y < m-1){
            int color = gridColor(x,y);
            return (board[x][y] == 0 or board[x][y] == color) and (board[x+1][y] == 0 or board[x+1][y] == color) and (board[x][y+1] == 0 or board[x][y+1] == color) and (board[x+1][y+1] == 0 or board[x+1][y+1] == color);
        }
        return false;
    }

    void setv(int x,int y,int value){
        if(x >= 0 and x < n and y >= 0 and y < m) board[x][y] = value;
    }

    void solve() {
        cin >> n >> m;
        board = vector<vector<int>>(n,vector<int>(m,0));
        for (auto& row : board)
            for (auto& x : row) cin >> x;
        queue<pair<int,int>> queue;
        for(int i = 0;i < n-1;i++){
            for(int j = 0;j < m-1;j++){
                if(isGrid(i,j)) queue.push({i,j});
            }
        }
        vector<vector<int>> moves;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        while(!queue.empty()){
            auto curr = queue.front();
            queue.pop();
            if(visited[curr.first][curr.second]) continue;
            visited[curr.first][curr.second] = true;
            int x = curr.first,y = curr.second;
            moves.push_back({x+1,y+1,gridColor(x,y)});
            setv(x,y,0),setv(x+1,y,0),setv(x,y+1,0),setv(x+1,y+1,0);
            vector<pair<int, int>> children = {{x-1,y-1},{x-1,y},{x-1,y+1},{x,y-1},{x,y+1},{x+1,y-1},{x+1,y},{x+1,y+1}};
            for (auto& child : children){
                if(isGrid(child.first,child.second)) queue.push({child.first,child.second});
            }
        }
        ll sum = 0;
        for (auto& row : board){
            for (auto& ele : row) sum += ele;
        }
        if(sum != 0) return deb(-1);
        int count = 0;
        for (auto& move : moves) if(move[2] != 0) count++;
        deb(count);
        for(int i = moves.size()-1;i >= 0;i--){
            auto top = moves[i];
            if(top[2] != 0) deb(top);
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