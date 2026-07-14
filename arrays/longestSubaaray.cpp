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

int subarrayByhash(vector<int> &nums, long long k){ 
    
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    // If prefix sum 'rem' exists, then the subarray after that index
// up to the current index has sum = k.

    for(int i =0; i<nums.size();i++){
        sum += nums[i];
        if(sum ==k){
            maxLen = max(maxLen, i+1);

        }
        long long rem = sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){ // have we ever seen prefix sum (sum-k)
            int len = i - preSumMap[rem]; // find tries to find whehter rem exits in the map or not 
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){ // we only insert prefix sum if it is not already present as we want to find the largest subaraay
        preSumMap[sum] =i; 
        }


    }
    return maxLen;
}
int main(){
    int n ;
    long long s;
    cout << "Enter the size of the array";
    cin>> n;
    cout<< "Enter the sum of the numbers:";
    cin >> s;

     vector<int> arr1(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }; 
    cout<<  subarray(arr1, s)<< endl;
    cout << subarrayByhash(arr1, s);
}

// sum = current balance.
// You want a subarray whose sum is k.
// So you ask: "Have I ever had a balance of sum - k before?"
// If yes, then everything between that earlier point and the current index sums to exactly k.
// Subarray Sum = current prefix sum - previous prefix sum