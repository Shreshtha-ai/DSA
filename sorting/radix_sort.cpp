#include<bits/stdc++.h>
using namespace std;

void countsort(vector<int> &arr , int digitplace){

    vector<int> output(arr.size());
    int count[10] = {0};

    for(int i=0;i<arr.size();i++){
        int digit = (arr[i]/digitplace)%10;
        count[digit]++;
        
    }
    for(int i=0; i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i = arr.size()-1;i>=0;i--){
        int digit = (arr[i]/digitplace)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
        
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=output[i];
    }




}


void radixsort(vector<int> &arr){
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    int digitplace =10;
    while(max/digitplace>0){
        countsort(arr,digitplace);
        digitplace*=10;

    }

}


int main(){
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixsort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}