#include <bits/stdc++.h>
using namespace std; using ll = long long;

vector<pair<int, int>> counts;
vector<vector<int>> dp;
int n;

int fun(int a,int b){
    // cout << "Fn call " << a << ' ' << b << '\n';
    if(dp[a][b] != -1) return dp[a][b];
    int ans = 0;
    for(int i = a;i <= b;i++){
        int tans = counts[i].first*counts[i].second;
        int ri = i+1,li = i-1;
        if(ri < n and counts[ri].first == counts[i].first+1) ri++;
        if(li >= 0 and counts[li].first == counts[i].first-1) li--;
        if(li >= a) tans += fun(a,li);
        if(ri <= b) tans += fun(ri,b);
        ans = max(ans,tans);
    }
    dp[a][b] = ans;
    return ans;
}

int main(){
    cin >> n;
    vector<int> a(n);
    for(auto &_ : a) cin >> _;
    sort(a.begin(),a.end());
    for(auto x : a){
        if(counts.size() == 0 or counts.back().first != x) counts.push_back({x,1});
        else counts.back().second++;
    }
    n = counts.size();
    dp = vector<vector<int>>(n,vector<int>(n,-1));
    cout << fun(0,n-1) << '\n';
    // for (auto& row : dp) {
    //     for (auto& col : row) cout << col << ' ';
    //     cout << '\n';
    // }
    return 0;
}