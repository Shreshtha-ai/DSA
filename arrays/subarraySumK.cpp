#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k){ //tc O(n^3) sc O(1)
    int n = nums.size();
    int cnt =0;

    for(int i=0;i<n;i++){
        for(int j=i; j<n;j++){
            int sum =0;
            for(int k=i; k<=j;k++){
                sum = sum+nums[k];
            }
            if(sum == k){
                cnt++;
                
            }

        }
    }
    return cnt;

}

int subarraySumBetter( vector<int>& nums, int k){ //TC O(n^2) SC O(1)
    int n = nums.size();
    int cnt =0;

    int left, right =0; // takin two pointers left and right to find the subarray sum
    int sum =0;
    for(int i=0;i<n;i++){
        sum =0;
        for(int j=i; j<n;j++){
            sum = sum+nums[j];
            if(sum == k){
                cnt++;
                
            }

        }
    }
    return cnt;
}

int subarraySumOptimal(vector<int>& nums, int k){ //TC =O(N) SC = O(N)
    int n = nums.size();
    int cnt =0;
    unordered_map<int,int> mp; // to store the prefix sum and its frequency
    int prefixsum =0;
    
    mp[0] = 1; // to handle the case when the prefix sum is equal to k

    for(int i=0;i<n;i++){
        prefixsum += nums[i];
        if(mp.find(prefixsum - k) != mp.end()){ // check if the prefix sum - k is present in the map
            cnt += mp[prefixsum - k]; // add the frequency of the prefix sum - k to the count
        }
        mp[prefixsum]++; // increment the frequency of the current prefix sum
    }
    return cnt;

}

int main(){
    int n;
    cout<< "Enter the number of elements in the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<< "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<< "Enter the target sum: ";
    cin>>k;
    int result = subarraySumOptimal(nums, k);
    cout<< "Number of subarrays with sum equal to " << k << ": " << result << endl;
    return 0;
}