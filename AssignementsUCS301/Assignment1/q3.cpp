#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[100];
    cout<< "Enter the number of elements for the array";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    cout << "Enter the number of positions to rotate: ";
    int d;
    cin >> d;
     reverse(a, a+d);

    reverse(a+d, a+n);
    reverse(a,a+n);

    cout << "Array after rotation: ";
    for(int i = 0; i<n; i++){
        cout<< a[i]<<" ";
    }
    cout << endl;
}