#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string str;
    cin>>str;
    unordered_map<char, int> mp;
    for(int i=0;i<str.size();i++) mp[str[i]]++;
    int count = 0;
    for(auto &it:mp) count += it.second & 1;
    if(count>1) cout<<"NO SOLUTION";
    else {
        string a = "", b = "", mid = "";
        for(auto &it:mp){
            if(it.second & 1){
                mid.push_back(it.first);
                for(int i=0;i<it.second/2;i++){
                    a.push_back(it.first);
                    b.push_back(it.first);
                }
            }
            else{
                for(int i=0;i<it.second/2;i++){
                    a.push_back(it.first);
                    b.push_back(it.first);
                }
            }
        }
        reverse(b.begin(), b.end());
        cout<<a<<mid<<b;
    }
}
