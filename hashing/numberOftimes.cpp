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
    cout<<"What number do you want to find the frequency of? ";
    int x;
    cin>> x;
    int count = 0;

    for(int i=0; i<n; i++){
        if(arr[i] ==x){
            count++;
        }
    }
    cout<<"The frequency of "<<x<<" is: "<<count<<endl;


}
//time complexity is o(n) and space complexity is o(1)