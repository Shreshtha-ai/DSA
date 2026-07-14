#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    int n = nums.size();
    for(int i =0; i<n;i++){
        for(int j = i+1; j<n; j++){
            if(nums[i]+nums[j]==target){
                return{i,j};
            }
        }
    }
    return {-1,-1};
        
    }

int main(){
    int n, sum;
    cout << "Enter the size of the array";
    cin>> n;
    cout<< "Enter the target sum you want:";
    cin>> sum;

     vector<int> arr1(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];

    }; 
    vector<int> ans = twoSum(arr1, sum);


    for (int x : ans) {
    cout << x << " ";
}
}