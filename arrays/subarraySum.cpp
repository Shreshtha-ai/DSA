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

    int maxSubArray2(vector<int>& nums) { // TC = O(N^3) SC = O(1)
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

    int main(){
        int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
}
int a = maxSubArray2(arr);
cout << a;
    


}
