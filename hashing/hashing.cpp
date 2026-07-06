#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin>> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n;i++){
        cin>> arr[i];
    }
    // precompute 
    int hash[13] = {0};
    for(int i = 0; i<n; i++){
        hash[arr[i]] +=1;
    }
    cout<<"What number do you want to find the frequency of? ";
    int x;
    cin>> x;

    cout<< hash[x]<< endl;
    
}