#include<bits/stdc++.h>
using namespace std;
//brute force approach 

// vector<int> findUnion(int arr1[], int arr2[], int n , int m){
//     set <int> st; // decelraing a set 
//      for (int i = 0; i < n; i++) {
//             st.insert(arr1[i]);
//         }

//         // Insert elements from second array
//         for (int i = 0; i < m; i++) {
//             st.insert(arr2[i]);
//         }

//         // Convert set to vector
//         vector<int> unionArr(st.begin(), st.end());
//         return unionArr;
// } 

//optimal solution 
vector<int> findUnion(int arr1[], int arr2[], int n, int m){ // double pointer method 
    vector<int> Union;
    int i = 0, j = 0;

    while( i<n && j<m){
        if(arr1[i]<arr2[j]){
            if(Union.empty() || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        }
        else if(arr2[j]<arr1[i]){
            if(Union.empty() || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            }
            j++;

        }
        else {
             if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++; j++;

        }
    }
    while(i<n){
         if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
    }
    while(j<m){
        if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
    }
    return Union;

}
// time complexity is O(n+m)
//space complexity is 0(n+m)





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
// time complexity is 0((m+n)log(m+n)) for brute force

// space complexity is O(m+n) for brute force 