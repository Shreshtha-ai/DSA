#include<bits/stdc++.h>
using namespace std;

int consecutiveOne(vector<int> &nums){
    int cnt = 0;
    int maxi = 0;

    for(int i=0; i<nums.size();i++){
        if(nums[i]==1){
            cnt++;
        
        }
        else{
            cnt = 0;
        }
        maxi = max(maxi,cnt);
    }
    return maxi;
}

int main(){
    int n ;
    cout << "Enter the size of the array";
    cin>> n;
     vector<int> arr1(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }; 
    cout<< consecutiveOne(arr1);
}