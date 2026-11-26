#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    vector<int> heap;
    void insert(int value){ //TC = O(logn) 
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


void heapify(int index){
    int left = 2*index+1;

    int right = 2*index +2;
    if(left<heap.size()&& heap[left]>heap[index]){
        swap(heap[left], heap[index]);
        heapify(left);
    }

    if(right<heap.size()&& heap[right]>heap[index]){
        swap(heap[right],heap[index]);
        heapify(right);
    }
}

void deleteMaxHeap(int index){
    cout<<"Deleting the element "<< heap[index] << " from the heap" << endl;
    swap(heap[index],heap[heap.size()-1]);
    heap.pop_back();
    heapify(index);
}
};

int main(){
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    for(int i=0; i<h.heap.size(); i++){
        cout<<h.heap[i]<<" ";
    }
    cout<<endl;
    h.deleteMaxHeap(0);
    for(int i=0; i<h.heap.size(); i++){
        cout<<h.heap[i]<<" ";
    }
    return 0;
}


