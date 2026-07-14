#include<bits/stdc++.h>
using namespace std;

int subarray(vector<int> &nums, int s){ //time complexity = O(n^3)
    int n = nums.size();
    int maxlength = 0;
    for(int i = 0; i<n;i++){
        for(int j =i; j<n;j++){
            int sum = 0;
            for(int k = i; k<=j;k++){
                sum = sum + nums[k];
            }
            if(sum ==s){
                maxlength = max(maxlength, j-i+1);
            }
        }
    }
    return maxlength;
}

int main(){
    int n,s ;
    cout << "Enter the size of the array";
    cin>> n;
    cout<< "Enter the sum of the numbers:";
    cin >> s;

     vector<int> arr1(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }; 
    cout<<  subarray(arr1, s);
}