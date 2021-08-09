#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a,int b){
    if(a>b) return b;
    return a;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin  >> n;
        vector<int> a;
        int x;
        bool flag = false;
        for(int i = 0;i < n && !flag;i++){
            cin >> x;
            a.push_back(x);
        }
        for(int x : a){
            if(x < 0){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "NO\n";
        }
        else{
            cout<<"YES\n201\n";
            for(int i = 0;i <= 200;i++)cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}