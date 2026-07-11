#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<< "Enter the number of element in the array: ";
    cin>> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];

    }
    int nums;
    cout<< "Enter the number you wantr to search:";
    cin>> nums;

    for(int j = 0; j<n; j++){
        if(arr[j] ==  nums){
            cout<< j;
            break;
        }
    }
    return 0;
}