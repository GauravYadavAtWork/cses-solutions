#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void equalize(multiset<int>&left, multiset<int>&right, int k){
    while ((int)left.size() > (k + 1) / 2) {
        right.insert(*prev(left.end()));
        left.erase(prev(left.end()));
    }
    while ((int)left.size() < (k + 1) / 2) {
        left.insert(*right.begin());
        right.erase(right.begin());
    }
}

void solve(vector<int>&arr, int k){
    multiset<int> left, right;
    int i = 0, j = 0;
    while(i<arr.size()){
        // inserting the new element in the correct set
        if(!left.empty() && arr[i] <= *prev(left.end())) left.insert(arr[i]);
        else right.insert(arr[i]);

        if(i-j+1 == k){ // a valid window of size k
            // make the size of left and right set equal
            equalize(left, right, k);
            cout<<*prev(left.end())<<' '; // last element of left set is median
            // now we will remove the last element of the window and shrink the window size by 1
            if(left.find(arr[j])!=left.end()) left.erase(left.find(arr[j]));
            else right.erase(right.find(arr[j]));
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