#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int>& nums){
    int count0 = 0, count1 = 0, count2 = 0 ;
            for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        int index = 0;
                // Fill with 0s
        while(count0--) {
            nums[index++] = 0;
        }

        // Fill with 1s
        while(count1--) {
            nums[index++] = 1;
        }

        // Fill with 2s
        while(count2--) {
            nums[index++] = 2;
        }

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
sort012(arr);
    for(int x = 0; x < n; x++){
    cout<<arr[x];
    }

}
