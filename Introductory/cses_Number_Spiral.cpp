#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int y, int x){
    // x is the coloumn, y is the row
    int m = max(x, y);
    if(m&1){
        if(x==m){
            cout<<(1LL*m*m) - y + 1;
        }else{
            cout<<(1LL*(m-1)*(m-1))+x;
        }
    }else{
        if(x==m){
            cout<<(1LL*(m-1)*(m-1))+y;
        }else{
            cout<<(1LL*m*m) - x + 1;
        }
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        solve(x, y);
    }
}
