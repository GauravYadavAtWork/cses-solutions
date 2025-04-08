#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(int x, vector<int>&arr){
    set<int> st;
    st.insert(0), st.insert(x);
    map<int, int>removed; // sections removed
    priority_queue<int>pq; // for fast retrival of largest section
    pq.push(x); // first bydefault section
    for(int i=0;i<arr.size();i++){
        // find position of curr t light
        auto r = st.upper_bound(arr[i]);
        int high = *r;
        r--;
        int low = *r;
        st.insert(arr[i]); // inserting new t light

        // cout<<low<<" "<<arr[i]<<" "<<high<<endl;
        
        removed[high - low]++; // this section is broken down into two parts
        // now inserting the new broken sections into the max heap
        pq.push(high - arr[i]);
        pq.push(arr[i] - low);
        
        // now find the largest section which is not yet broken down
        while(!pq.empty() && removed.find(pq.top())!=removed.end()) {
            removed[pq.top()]--;
            if(removed[pq.top()]==0) removed.erase(pq.top());
            pq.pop();
        }

        cout<<pq.top()<<' ';
        
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>arr (m);
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    solve(n, arr);
}