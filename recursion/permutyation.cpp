#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums, vector<int> ds, vector<vector<int>>& ans, vector<int>& visited){
    if(ds.size() == nums.size()){
        ans.push_back(ds); // answer is found ds ia a vector of size n
        return;
    }

    for(int i =0; i<nums.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1; // mark the element as visited
            ds.push_back(nums[i]); // add the element to the current permutation
            solve(nums, ds, ans, visited); // recursive call
            ds.pop_back(); // backtrack
            visited[i] = 0; // unmark the element
        }
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> ds; // current permutation
    vector<int> visited(nums.size(), 0); // visited array to keep track of visited elements
    solve(nums, ds, ans, visited);
    return ans;
}

int main(){
    vector<int> nums;
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<vector<int>> result = permute(nums);
    for(const auto& perm : result){
        for(int num : perm){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
// tc =O(N!*N)  SC = O(N) + O(N) + O(N) (recursion stack space + visited array + ds vector)