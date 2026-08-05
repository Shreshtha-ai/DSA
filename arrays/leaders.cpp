#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& nums){ //TC = O(N^2) SC = O(N)
    vector<int> ans;

    for(int i=0; i< nums.size();i++){
        bool leader = true;
        for(int j =i+1; j<nums.size();j++){
            if(nums[j]>nums[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}
 
vector<int> leadersOptimized(vector<int>& nums){ //TC = O(N) SC = O(N)
    vector<int> ans;
    if(nums.empty()){
        return ans;
    }
    int maxi = INT_MIN;
    for(int i = nums.size()-1; i>=0; i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<int> ans = leaders(nums);
    cout<<"Leaders in the array are: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}