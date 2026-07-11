#include<bits/stdc++.h>
using namespace std;
// vector<int> Intersection(vector<int> &A, vector<int> &B, int  n , int m){
//     vector<int> ans;
//     int vis[m] = {0};
//     for(int i =0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if(A[i] ==B[j] && vis[j] ==0){
//                 ans.push_back(A[i]);
//                 vis[j ]=1;
//                 break;
//             }
//             if(B[j]> A[i]) break;
//         }
//     }
//     return ans;
// } // this is brute force approach here time complexity is O(N*M)

vector<int> Intersection(vector<int> &A, vector<int> &B, int n, int m){
    int i =0;
    int j = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<A[i]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans; // this is the optimal approach with time complexity O(N+M)


    
}
int main(){
    int n, m;
    cout << "Enter the size of the array";
    cin>> n;
     vector<int> arr1(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    };
    cout << "Enter the size of the array";
    cin>> m;
     vector<int> arr2(m);
    cout << "Enter the elements of array: ";
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    };

   vector<int> ans = Intersection( arr1, arr2, n, m  );

   for(int x: ans){
    cout<< x;
   }
    
    return 0;
}