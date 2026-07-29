#include<bits/stdc++.h>
using namespace std;

vector<int> ReaarangeArray(vector<int> &nums){ //SC = O(N/2+N/2 =N) TC = O(N+N/2)
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]); 
        }
        for(int i =0; i<n/2;i++){
            nums[2*i] = pos[i];
            nums[2*i +1] = neg[i];
        }
        return nums;
        
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
vector<int> a(n);
a = ReaarangeArray(arr);

for(int i =0; i<n;i++){
    cout<< a[i];
}
    }
