#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> arr(2*n),res(2*n);
    for(int i = 0;i < 2*n;i++)cin >> arr[i];
    sort(arr.begin(),arr.end());
    for(int i = 0;i < n;i++){
        res[2*i] = arr[i];
        res[2*i+1] = arr[2*n-i-1];
    }
    for(int x : res)cout << x << ' ';
    cout << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}