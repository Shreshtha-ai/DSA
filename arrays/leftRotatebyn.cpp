//brute force approach 
#include<bits/stdc++.h>
using namespace std;

void roatate(int arr[], int n , int d){

    d = d%n;

    int temp[d];
    for(int i = 0; i<d; i++){
        temp[i] = arr[i]; // store everything in temp 

    }
    for(int i = d; i<n; i++){
        arr[i-d] = arr[i];

    }
    
    for(int i = n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }

}

void rotate(int arr[], int n , int d){ // this is the optimal approach which take space complexity O(1)
    reverse(arr, arr+d);

    reverse(arr+d, arr+n);
    reverse(arr,arr+n);
}

int main(){
     int n;
    cout<< "Enter the number of elements for the array";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    
}
// roatate(arr,n,4);
// for(int i = 0; i<n; i++){
//         cout<< arr[i];
//     }
    rotate(arr,n,5);
    for(int i = 0; i<n; i++){
        cout<< arr[i];
    }


return 0;
}
// time complexity is O(N)
// space complexity is O(d)

