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

int main(){
    int n;
    cout<< "Enter the number of elements of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<< "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int ans = longest_seq(nums);
    cout<< "Length of longest consecutive sequence is: "<<ans;
}
