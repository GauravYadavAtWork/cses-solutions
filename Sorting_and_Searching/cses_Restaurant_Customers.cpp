#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>&in, vector<int>&out){
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    int i=0 , j = 0, count = 0, res = 0;
    while(i<in.size()){
        if(in[i]<out[j]){
            count++;
            i++;
        }else{
            count--;
            j++;
        }
        res = max(res, count);
    }
    cout<<res;
}

int main(){
    int n;
    cin>>n;
    vector<int> in(n);
    vector<int> out(n);
    for(int i=0;i<n;i++) cin>>in[i]>>out[i];
    solve(in, out);
}
