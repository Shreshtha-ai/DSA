#include<bits/stdc++.h>
using namespace  std;
void sort(int arr[], int n){
    for(int i = n-1; i>=0; i--){
        int didswap =0;
        for(int j = 0; j<=i-1; j++){
            if(arr[j]> arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap = 1; // optimised
            }
        }
        if(didswap ==0){
            break;
        }
    }
    cout << "After bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main() {
    // Initialize array
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // Print array before sorting
    cout << "Before bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Call bubble sort
    sort(arr, n);

    return 0;
}