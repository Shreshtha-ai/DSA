#include<bits/stdc++.h>
using namespace std;

void deleteMaxHeap(vector<int>& heap){
    if(heap.size()==0){
        cout<<"Heap is empty"<<endl;
        return;
    }
    if(heap.size()==1){
        heap.pop_back();
        return;
    }

    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    int index =0;
    while(index<heap.size()){
        int left = 2*index +1;
        int right = 2*index +2;
        int largest = index;
        if(left<heap.size() && heap[left]>heap[largest]){
            largest = left;
        }
        if(right<heap.size() && heap[right]>heap[largest]){
            largest = right;
        }
        if(largest!=index){
            swap(heap[largest], heap[index]);
            index = largest;
        }
        else{
            break;
        }
    }
}
