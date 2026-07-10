#include<bits/stdc++.h>

using namespace std;

bool isSorted( int arr[], int n){
 for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])  // If any element is smaller than the previous one, return false
            return false;
    }

    return true;  
}
int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];

}

printf( isSorted(arr, n) ? "True": "False");
}