#include<bits/stdc++.h>
using namespace std;
int second_smallest(int arr[], int n){
     if (n < 2)
        return -1;

    int small = INT_MAX;
    int second_small = INT_MAX;

    // Loop through the array to find the second smallest element
    for (int i = 0; i < n; i++) {
        // Update the smallest and second smallest values
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        } 
        else if (arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }
    return second_small;
}

// Function to find the second largest element in the array
int second_largest(int arr[], int n) {
    // Edge case: if the array has fewer than 2 elements
    if (n < 2)
        return -1;

    int large = INT_MIN, second_large = INT_MIN;

    // Loop through the array to find the second largest element
    for (int i = 0; i < n; i++) {
        // Update the largest and second largest values
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } 
        else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large; // Return the second largest element
}
int main(){
    int n;
    cout << "Enter the size of the array";
    cin>> n;
     int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];

    
}
int x = second_smallest(arr,n);
int y = second_largest(arr,n);

cout << x<<endl;
cout <<y <<endl;
}

// time complexity is O(n)