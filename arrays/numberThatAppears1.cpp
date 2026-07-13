#include<bits/stdc++.h>
using namespace std;

int singleElement( vector<int>& arr){ // time complexity = o(n^2) //space complexity = o(1)
    int n = arr.size();
    for(int i=0; i<n; i++){
        int num = arr[i];
        int cnt = 0;
        for(int j=0; j<n;j++){
            if(arr[j]==num){
            cnt++;
            }
        }
        if (cnt ==1 ) return num;


    }
    return -1;
}

int singleElementbyHash(vector<int>& arr){ // time complexity = o(n) space complexity is o(n)
    int n = arr.size();
    int maxi = arr[0];
    for(int i = 0; i<n;i++){
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi+1, 0);
    for(int i =0; i<n; i++){
        hash[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(hash[arr[i]] ==1){
        return arr[i];
        }
    }
    return -1;

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
    cout<< singleElement(arr1)<<endl;
    cout << singleElementbyHash(arr1);
}