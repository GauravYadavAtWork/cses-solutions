#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n;
    cin>>n;
    ll s = (1LL*n*(n+1))/2;
    if(s&1) cout<<"NO"<<'\n';
    else{
        cout<<"YES"<<'\n';
        s/=2;
        vector<int> arr;
        int m = n;
        while(s){
            if(n<=s){
                arr.push_back(n);
                s -= n;
                n--;
            }else{
                arr.push_back(s);
                s = 0;
            }
        }
        cout<<arr.size()<<'\n';
        for(int i = arr.size()-1;i>=0;i--){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        cout<<m - arr.size()<<'\n';
        int i = 0;
        while(m){
            if(arr[i]==m){
                i++;
            }else{
                cout<<m<<' ';
            }
            m--;
        }
        cout<<'\n';
    }
}
