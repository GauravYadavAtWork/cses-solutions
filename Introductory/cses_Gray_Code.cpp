#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(string&str, vector<int>&n){
    cout<<str<<'\n';
    for(int i=0;i<n.size();i++){
        if(n[i]){
            n[i] = 0;
            str[i] = str[i]=='0' ? '1' : '0';
            for(int j=0;j<i;j++) n[j] = 1;
            solve(str, n);
            return;
        }
    }
}

int main(){
    int n;
    cin>>n;
    string str = "";
    vector<int> bit (n, 1);
    for(int i=0;i<n;i++){
        str.push_back('0');
    }
    solve(str, bit);
}
