#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<< "Enter the number of elements of array: ";
    cin>>n;
    int a[n];
    cout<< "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int left = 0;
    int right = n-1;
    while(left<right){
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
    cout<< "Reversed array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}