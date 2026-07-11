//brute force approach 
#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n , int m){
    set <int> st;
     for (int i = 0; i < n; i++) {
            st.insert(arr1[i]);
        }

        // Insert elements from second array
        for (int i = 0; i < m; i++) {
            st.insert(arr2[i]);
        }

        // Convert set to vector
        vector<int> unionArr(st.begin(), st.end());
        return unionArr;
}

int main(){
    int n, m;
    cout << "Enter the size of the array";
    cin>> n;
     int arr1[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    };
    cout << "Enter the size of the array";
    cin>> m;
     int arr2[m];
    cout << "Enter the elements of array: ";
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    };

   vector<int> ans = findUnion( arr1, arr2, n, m  );

   for(int x: ans){
    cout<< x;
   }
    
    return 0;
}
// time complexity is 0((m+n)log(m+n))
// space complexity is O(m+n)