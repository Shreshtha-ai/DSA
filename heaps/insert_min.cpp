#include<bits/stdc++.h>
using namespace std;

void insertMinHeap(vector<int>& heap , int value){
    heap.push_back(value); // TC = O(logn)
    int i = heap.size()-1;
    while(i>=0){
        int parent = (i-1)/2;
        if(heap[parent]>heap[i]){ 
            swap(heap[parent], heap[i]); //tc = O(1)    
            i = parent;
        }
        else{
            break;
        }
    }

} 


int main(){
    vector<int> heap;
    insertMinHeap(heap, 10);
    insertMinHeap(heap, 20);
    insertMinHeap(heap, 5);
    insertMinHeap(heap, 30);
    insertMinHeap(heap, 15);

    for(int i=0; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    return 0;
}