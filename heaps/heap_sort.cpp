#include <bits/stdc++.h>
using namespace std;

class Heap {
    public:
    vector<int> v;
    void insert(int value){
        v.push_back(value);
        int cur_index = v.size()-1;
        while(cur_index!=0){
            int parent_index = (cur_index-1)/2;
            if(v[parent_index]>v[cur_index]){
                swap(v[parent_index], v[cur_index]);
            }
            cur_index = parent_index;
        }
    }
    
    void Heapify(int index) {
        int left_child = 2*index+1;
        int right_child = 2*index+2;
        if(left_child<v.size() && v[left_child]<v[index]){
            swap(v[index], v[left_child]);
            Heapify(left_child);
        }
        if(right_child<v.size() && v[right_child]<v[index]){
            swap(v[index], v[right_child]);
            Heapify(right_child);
        }
    }
    
    void delete_from_heap(){
        int index = 0;
        swap(v[index], v[v.size()-1]);
        v.pop_back();
        Heapify(index);
    }
    
};

void heapSort(vector<int>& arr){
    Heap h;
    
    for(int i=0; i<arr.size();i++){
        h.insert(arr[i]);
    }
    int index = 0;
    while(!h.v.empty()){
        arr[index] = h.v[0];
        h.delete_from_heap();
        index++;
    }
}


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>> arr[i];
        
    }
    heapSort(arr);
    
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
    return 0;
    

}
