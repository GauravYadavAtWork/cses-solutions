#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    cin>>str;
    int i = 1, res = 1, curr = 1;
    while(i<str.size()){
        if(str[i]!=str[i-1]) curr = 1;
        else curr ++;
        res = max(res, curr);
        i++;
    }
    cout<<res;
}
