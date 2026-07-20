#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums){
        int n = nums.size();
                for (int i = 0; i < n; i++) {
            
            int cnt = 0; 
            
            // Count the frequency of nums[i] in the array
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }
            
            // Check if frequency of nums[i] is greater than n/2
            if (cnt > (n / 2)) {
                return nums[i]; 
            }
        }
        
        return -1; 
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
int a = majorityElement(arr);
cout << a;
    


}