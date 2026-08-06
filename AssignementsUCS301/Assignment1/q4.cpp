#include<bits/stdc++.h>
using namespace std;

void reverse(int a[], int start, int end){
    while(start<end){
        swap(a[start], a[end]);
        start++;
        end--;
    }
    return;
    
}
    

int main(){
    
    int n;
    int a[100];
    cout<< "Enter the number of elements for the array";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    cout << "Array after reversal: ";
    reverse(a, 0, n-1);
    for(int i = 0; i<n; i++){
        cout<< a[i]<<" ";
    }
    cout << endl;
}