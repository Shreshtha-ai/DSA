#include<bits/stdc++.h>
using namespace std;

void insertMaxHeap(vector<int>& heap, int value){ //TC = O(logn) 
    heap.push_back(value);
    int index = heap.size()-1;
    while(index>0){
        int parent = floor((index-1)/2);
        if(heap[parent]<heap[index]){
            swap(heap[parent], heap[index]);
            index = parent;
        }
        else{
            break;
        }
    }

}


int main(){
    vector<int> heap;
    insertMaxHeap(heap, 10);
    insertMaxHeap(heap, 20);
    insertMaxHeap(heap, 5);
    insertMaxHeap(heap, 30);
    insertMaxHeap(heap, 15);

    for(int i=0; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    return 0;
}