#include<bits/stdc++.h>
using namespace std;

    
    int maxSubArray(vector<int>& nums) { // TC = O(N^3) SC = O(1)
        int maxi = INT_MIN;

        for(int i =0; i<nums.size(); i++){
            for(int j =i; j<nums.size(); j++){
                int sum = 0;
                for(int k = i; k<=j; k++){
                    sum += nums[k];
                }
                maxi = max(maxi,sum);
            }
        }

        return maxi;

        
    }

    int maxSubArray2(vector<int>& nums) { // TC = O(N^2) SC = O(1)
        int maxi = INT_MIN;

        for(int i =0; i<nums.size(); i++){ 
            int sum = 0;

            for(int j =i; j<nums.size(); j++){
                    sum += nums[j];
                
                maxi = max(maxi,sum);
            }
        }

        return maxi;

        
    }


    int maxSubArray3(vector<int>& nums){ // optimal approach by using kadanes algorithm TC = O(N) SC = O(1)
       int maxi = INT_MIN;
       int sum =0;
       for(int i =0; i<nums.size();i++){
        sum += nums[i]; 
        if (sum > maxi) {
                maxi = sum; 
            }
            if (sum < 0) {
                sum = 0; 
            }


       }
       return maxi;

    }
    
    int printmaxSubArray(vector<int>&nums){
        int maxi = INT_MIN;
        int sum =0;
        // starting index of current subarray
        int start = 0; 
        int ansStart = -1, ansEnd = -1; 
        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0) {
                start = i;
            }
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;
        
        // Return the maximum subarray sum found
        return maxi;
    }
 



    
    int main(){
        int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
}
int a = printmaxSubArray(arr);
cout << a;
    


}
