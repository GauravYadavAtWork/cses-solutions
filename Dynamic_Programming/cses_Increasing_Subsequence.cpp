#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

class Solution{
public:
    int lis(vector<int>&arr){
        vector<int> dp;
        for(int i=0;i<arr.size();i++){
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            if(it != dp.end()) *it = arr[i]; // update the index
            else dp.push_back(arr[i]);
        }
        return dp.size();
    }
};


int main(){
    int n;
    cin>>n;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution s;
    cout<<s.lis(arr);
}
