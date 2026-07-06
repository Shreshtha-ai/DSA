#include<bits/stdc++.h>
using namespace std;

void  reverseArray(int arr[], int start, int end){
    if(start >=end)
        return;
        swap(arr[start], arr[end]);
    reverseArray(arr, start+1, end-1);
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
    reverseArray(arr, 0, n-1);
    cout << "Reversed array is: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

