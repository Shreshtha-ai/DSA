#include<bits/stdc++.h>
using namespace std;

vector<int> next_permute(vector<int> &nums){ //TC = O(3N) SC = O(1)
    int ind = -1;
    for(int i = nums.size() - 2; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    }
    for(int i = nums.size() - 1; i > ind; i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }


    }
    reverse(nums.begin() + ind + 1, nums.end());
    return nums;
    // in this code we first find a number which is smaller than its next number from the right side of the array. 
    // If we find such a number then we will find a number which is greater than this number from the right side of the array and swap them. 
    // After that we will reverse the numbers after the index of the first number we found. 
    //If we don't find any such number then we will reverse the whole array.

}