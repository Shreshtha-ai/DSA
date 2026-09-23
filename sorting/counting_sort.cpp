#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    int count[n] = {0};
    for(int i = 0; i<n; i++){
        count[arr[i]]++;
    }
    int total=0;
    for(int i = 0; i<n; i++){
        count[i]= total+count[i];
        total+=count[i];
    }
    int output[n];
    for(int i = n-1; i>=0; i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i<n; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[6];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < 6; i++){
        cin >> arr[i];
    }
    for
    sort(arr, 6);
    cout << "After counting sort: " << "\n";
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
