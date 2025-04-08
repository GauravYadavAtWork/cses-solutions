#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums){
    int i=0, j=0, result = 0, ones = 0, t = 0;
    while(j+1<nums.size()){
        if(nums[j+1]){
            ones += nums[j];
            t++;
        }else{
            ones += nums[j];
            ones -= nums[i];
            i++;
        }
        result = max(result, ones);
        j++;
        cout<<i<<" "<<j<<endl;
    }
    return t - result;
}

int main(){
    vector<int> arr = {0,0,0,0,1,1,1,0,1,0,0,0,0};
    cout<<solve(arr);
}