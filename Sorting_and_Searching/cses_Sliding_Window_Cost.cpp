#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void equalize(multiset<int>&left, multiset<int>&right, int k, ll&leftsum, ll&rightsum){
    while ((int)left.size() > (k + 1) / 2) {
        auto it = prev(left.end());
        int val = *it;
        left.erase(it);
        leftsum -= val;
        right.insert(val);
        rightsum += val;
    }
    while ((int)left.size() < (k + 1) / 2) {
        auto it = right.begin();
        int val = *it;
        right.erase(it);
        rightsum -= val;
        left.insert(val);
        leftsum += val;
    }
}

void solve(vector<int>&arr, int k){
    multiset<int> left, right;
    int i = 0, j = 0;
    ll leftsum = 0, rightsum = 0;
    while(i<arr.size()){
        // inserting the new element in the correct set
        if(!left.empty() && arr[i] <= *prev(left.end())) left.insert(arr[i]), leftsum+=arr[i];
        else right.insert(arr[i]), rightsum += arr[i];

        if(i-j+1 == k){ // a valid window of size k
            // make the size of left and right set equal
            equalize(left, right, k, leftsum, rightsum);
            int median = *prev(left.end()); // last element of left set is median
            cout<<((1LL*(int)(left.size())*median) - leftsum) + (rightsum - (1LL*(int)(right.size())*median))<<' ';
            // now we will remove the last element of the window and shrink the window size by 1
            if(left.find(arr[j])!=left.end()) left.erase(left.find(arr[j])), leftsum-=arr[j];
            else right.erase(right.find(arr[j])), rightsum-=arr[j];
            j++; // shrink the window
        }
        // cout<<"sizes "<<left.size()<<" "<<right.size()<<endl;
        i++;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr, k);
}