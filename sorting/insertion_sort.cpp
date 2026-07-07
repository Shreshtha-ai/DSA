#include<bits/stdc++.h>

using namespace std;

void sort(int arr[], int n){
    for(int i = 0; i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }
}


 cout << "After insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Before insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Call bubble sort
    sort(arr, n);

    return 0;
}