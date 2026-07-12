#include<bits/stdc++.h>
using namespace std;

int missing(vector<int>& arr){

    int n = arr.size()+1;

    for(int i =1; i<=n;i++){
        bool found = false;
        for(int j =0; j<n-1; j++){
            if(arr[j]==i){
                found = true;
                break;
            }
        }

        if(!found)
        return i;




    }
    return -1;
}// time complexity = O(N^2) SPACE COMPLEXITY = O(1)
 

int hashmissing(vector<int>& arr){
    int n = arr.size()+1;

    vector<int> hash(n+1,0);

    for(int i =0; i<n-1; i++){
        hash[arr[i]]++;

    }
    for(int i =1; i<=n; i++){
        if(hash[i] ==0){
            return i;
        }
    }
    return -1;
} //time complexity = O(n) space complexity = O(n)
int summissing(vector<int>& arr){
    int n = arr.size()+1;
    int sum = 0;

    for(int i=0; i<n-1;i++){
        sum +=arr[i];
    }
    long long totalSum = (n*(n+1))/2;

    return totalSum - sum;
} //time complexity = O(n) space complexity = O(1)

int xormissing(vector <int>& arr){
    int n = arr.size()+1;
    int xor1 =0, xor2 = 0;
    for(int i =0; i<n-1; i++){
        xor2 = xor2^arr[i];
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^n;
    return xor1^xor2;

} // space complexity = O(1) time complexity = O(n)
// but it is better then sum because while calculating sum we take long long which takes  more space than integer 

int main(){
    int n ;
    cout << "Enter the size of the array";
    cin>> n;
     vector<int> arr1(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }; 
    cout << missing(arr1)<<endl;
    cout <<hashmissing(arr1)<<endl ;
    cout<< summissing(arr1)<<endl;
    cout << xormissing(arr1);
} 

