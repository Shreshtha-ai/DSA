// this the the best approach by using double pointer 
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr){

    if (arr.empty()){
        return 0;
    }
    int i =0;
    for(int j = 0; j<arr.size(); j++){
        if(arr[j]!= arr[i]){
            i++;
            arr[i]= arr[j];
        }
    }
    return i+1;
}
int main() {
     int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
}
  int k = removeDuplicates(arr);

  for(int x = 0; x < k; x++){
    cout<<arr[x];
  }
}

// this code only works if the array is sorted first then only the duplicates will be removed 
// time complexity of this is O(N) as we move through the only once 