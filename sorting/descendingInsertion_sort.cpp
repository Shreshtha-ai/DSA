#include<bits/stdc++.h>
using namespace std;


void descendingInsertionsort(int arr[], int n){
    for(int i =0;i<=n-1;i++){
        int j =i;
        while(j>0 && arr[j-1]<arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main(){
    int arr[5];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    descendingInsertionsort(arr, 5);
    cout << "After descending insertion sort: " << "\n";
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}