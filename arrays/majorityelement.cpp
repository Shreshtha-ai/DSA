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

int majorityElementsHash(vector<int>& nums){  
    map<int,int>mp; // TC = O(NlogN) SC = O(N)
    for(int i =0; i<nums.size(); i++){
        mp[nums[i]]++ ;


    }
    for(auto it:mp){
        if(it.second>(nums.size()/2)){
            return it.first;
        }
    }
    return -1;
}

int majorityElementbyMVA(vector<int>& nums){  //TC = O(N)+ O(N) SC = O(1) using moore voting algorithm 
    int cnt =0;
    int el;
    for(int i = 0; i<nums.size();i++){
        if(cnt ==0){
            cnt =1;
            el = nums[i];
        }
        else if(nums[i] ==el){
            cnt++;

        }
        else {
            cnt --;

        }

        }

        int cnt1 =0;
        for(int i =0; i<nums.size();i++){
            if(nums[i] == el){
                cnt1++;
            }

        }
        if(cnt1> (nums.size()/2)){
            return el;
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
int a = majorityElementbyMVA(arr);
cout << a;
    


}