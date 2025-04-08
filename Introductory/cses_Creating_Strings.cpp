#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(string&temp, vector<int>&freq, int l, vector<string>&bag){
    if(l==temp.size()){
        // cout<<temp<<'\n';
        bag.push_back(temp);
        return;
    }
    for(int i=0;i<26;i++){
        if(freq[i]){
            temp.push_back(char('a' + i));
            freq[i]--;
            solve(temp, freq, l, bag);
            freq[i]++;
            temp.pop_back();
        }
    }
}

int main(){
    string str;
    cin>>str;
    vector<int> f(26, 0);
    for(int i=0;i<str.size();i++){
        f[str[i]-'a']++;
    }
    string temp = "";
    vector<string> bag;
    solve(temp, f, str.size(), bag);
    cout<<bag.size()<<'\n';
    for(auto &item:bag) cout<<item<<'\n';
}
