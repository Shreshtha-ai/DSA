#include<bits/stdc++.h>
using namespace std;
void zeroes(vector<int>& nums){
    int j = -1;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }
    if(j ==-1 ) return;
    for(int i = j+1; i<n; i++){
        if(nums[i]!=0){
            swap(nums[i], nums[j]);
            j++;
        }

    }
}    int main() {
     int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    zeroes(arr);
    for(int x = 0; x < n; x++){
    cout<<arr[x];
    }
    return 0;
}
// time complexity is O(N)
//space complexity is O(1) since we are not using any extra space 