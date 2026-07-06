#include<bits/stdc++.h>

using namespace std; 
int main (){
    int n;
    int maxi = 0;
    int maxElement, minElement;
    int min = INT_MAX;
    cout<< "Enter the number of elements for array: ";
    cin>> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n;i++){
        cin>> arr[i];
    }
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

     for (auto it : mp) {
        if (it.second > maxi) {
            maxi= it.second;
            maxElement = it.first;
        }
        if (it.second < min) {
            min= it.second;
            minElement = it.first;
        }
    }
    cout<<"What number do you want to find the frequency of? ";
    int x;
    cin>> x;
    cout<< mp[x];
     cout << "Maximum Frequency Element = " << maxElement
         << " (" << maxi<< " times)\n";

    cout << "Minimum Frequency Element = " << minElement
         << " (" << min << " times)\n";

}

