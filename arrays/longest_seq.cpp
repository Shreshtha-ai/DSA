#include<bits/stdc++.h>
using namespace std;

bool linearsearch(vector<int> &nums, int target){ //TC = O(n)
    for(int i=0;i<nums.size();i++){
        if(nums[i] == target){
            return true;
        }
    }
    return false;
}


int longest_seq(vector<int> &nums){ //TC = O(n^2) //SC = O(1) 
    if(nums.size() ==0){
        return 0;
    }
    int n = nums.size();
    int longest =1;
    
    for(int i=0;i<n;i++){
        int cnt =1;
        int x = nums[i];
        while(linearsearch(nums,x+1)==true){
            cnt++;
            x++;
        }
        longest = max(longest,cnt);
    }
    return longest;

    
     
}


int longestConsecutive(vector<int>& nums){ //TC = O(nlogn) because of sorting //SC = O(1) 
    int n = nums.size();
    if(n==0) return 0;

    sort(nums.begin(),nums.end());

    int lastSmalll = INT_MIN;
    int cnt =0;
    int longest =1;

    for(int i=0;i<n;i++){
        if(nums[i] == lastSmalll){
            continue;
        }
        else if(nums[i] == lastSmalll +1){
            cnt++;
        }
        else{
            cnt =1;
        }
        longest = max(longest,cnt);
        lastSmalll = nums[i];
    }

    return longest;
}
int main(){
    int n;
    cout<< "Enter the number of elements of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<< "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int ans = longestConsecutive(nums);
    cout<< "Length of longest consecutive sequence is: "<<ans;
}
