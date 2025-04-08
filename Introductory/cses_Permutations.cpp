#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    if(n==1) cout<<1;
    else if(n>1 && n<4){
        cout<<"NO SOLUTION";
    }else{
        if(n&1){// n is odd
            for(int i=n-1;i>0;i-=2) cout<<i<<" ";
            cout<<n<<" ";
            for(int i=1;i<n;i+=2) cout<<i<<" ";
        }else{
            for(int i=n-2;i>0;i-=2) cout<<i<<" ";
            cout<<n<<" ";
            for(int i=1;i<n;i+=2) cout<<i<<" ";
        }
    }
}
