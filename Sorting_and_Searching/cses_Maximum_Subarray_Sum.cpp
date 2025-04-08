#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll maxSubArray(vector<int>& nums) {
        ll maxsum=INT_MIN, sum=0;
        for(int i=0;i<nums.size();i++){
            if((sum+nums[i])<0){
                maxsum = max(maxsum,sum+nums[i]);
                sum=0;
            }else{
                sum+=nums[i];
                maxsum = max(maxsum,sum);
            }
        }
        return maxsum;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution s;
    cout<<s.maxSubArray(arr);
}