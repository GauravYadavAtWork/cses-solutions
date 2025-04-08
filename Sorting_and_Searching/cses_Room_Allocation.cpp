#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

// 1 2 4
// 2 4 4

void solve(vector<vector<int>>&enter, vector<vector<int>>&exit){
    sort(enter.begin(), enter.end());
    sort(exit.begin(), exit.end());
    int n = enter.size();
    vector<int> arr (n, -1);
    int roomNo = 0, i = 0, j = 0;
    vector<int> freeRooms;
    while(i < n || j < n){
        if(i < n && (j == n || enter[i][0] <= exit[j][0])){
            if(freeRooms.size()){
                arr[enter[i][1]] = freeRooms.back();
                freeRooms.pop_back();
            }else{
                roomNo++;
                arr[enter[i][1]] = roomNo;
            }
            i++;
        }else{
            freeRooms.push_back(arr[exit[j][1]]);
            j++;
        }
    }

    cout<<roomNo<<'\n';
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}



int main(){
    int n;
    cin>>n;
    vector<vector<int>>enter(n, vector<int>(2));
    vector<vector<int>>exit(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>enter[i][0]>>exit[i][0];
        enter[i][1] = i;
        exit[i][1] = i;
    }
    solve(enter, exit);
}