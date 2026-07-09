#include<bits/stdc++.h>
using namespace std;



int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i] <= pivot && i<=high-1 ){ // if we have to do in descending order arr[i]>= pivot
            i++;
        }
        while(arr[j]> pivot && j>=low+1 ){ // if we have to do in descending order arr[i]< pivot 
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;

}
void quicksort(vector<int> &arr, int low, int high){
    // Quicksort is a divide-and-conquer algorithm that works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

    // In this implementation, we choose the first element  as the pivot.

    if (low < high){
        int pIndex = partition(arr,low,high);
        quicksort(arr, low, pIndex-1);  // Recursively sort the left sub-array
        quicksort(arr, pIndex+1, high);
    }
}

  
int main() {
     int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
}
         quicksort(arr, 0, n-1);
    for (int x : arr){
        cout << x << " "; 
    }

}
//time complexity is o(nlogn)



