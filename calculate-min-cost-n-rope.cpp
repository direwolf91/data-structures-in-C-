/* Programme to calculate the minimum cost of connecting n ropes */
#include <iostream>
using namespace std;


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

 class Heap{
     int *harr;
     int capacity;
     int heap_size;
     int current_size;
 public:
    Heap(int*, int);
    int getSize();
    void insert();
    void createHeap();
    void printHeap();
    void heapify(int);
    void insert(int);
    int parent(int);
    int leftChildKey(int);
    int rightChildKey(int);
    int extractMin();
 };
 
 Heap::Heap(int *arr, int size){
     harr = arr;
     capacity = size;
     heap_size = size/2;
     current_size = size;
     createHeap();
 }
 
 int Heap::getSize(){
     return current_size;
 }
 
 void Heap::insert(int val){
     if (current_size >= capacity){
         cout << "\n Heap already full \n";
         return;
     }
     harr[current_size] = val;
     int index = current_size;
     current_size++;
     while (index != 0 && harr[parent(index)] > harr[index]){
         swap(&harr[parent(index)], &harr[index]);
         index = parent(index);
     }
 }
 
  int Heap::parent(int index){
     return (index - 1)/2;
 }
 
 int Heap::leftChildKey(int index){
     return (2*index + 1);
 }
 
 int Heap::rightChildKey(int index){
     return (2*index + 2);
 }
 
 void Heap::createHeap(){
     while(heap_size >= 0){
         heapify(heap_size);
         heap_size--;
     }
 }
 
 void Heap::printHeap(){
     for (int i = 0; i < getSize(); i++){
         cout << harr[i] << "\n";
     }
     cout << "\n";
 }
 
 void Heap::heapify(int index){
     int leftKey = leftChildKey(index);
     int rightKey = rightChildKey(index);
     int smallest = index;

     if(leftKey < current_size && harr[leftKey] < harr[index]){
         smallest = leftKey;
     }
     if (rightKey < current_size && harr[rightKey] < harr[smallest]){
         smallest = rightKey;
     }
     if (smallest != index){
         swap(&harr[smallest], &harr[index]);
         heapify(smallest);
     }
     
 }

int Heap::extractMin(){
    if(current_size == 0){
        cout << "\n No element present in heap \n";
        return -1;
    }
    if (current_size == 1){
        current_size--;
         return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[current_size - 1];
    current_size--;
    heapify(0);
    return root;
}

int minCost(int *arr, int size){
    int totalCost, length1, length2, tempSum;
    totalCost = 0;
    Heap h(arr, size);
    while(h.getSize() >= 2){
        length1 = h.extractMin();
        length2 = h.extractMin();
        tempSum = length1 + length2;
        totalCost+= tempSum;
        h.insert(tempSum);
    }
    return totalCost;
}

int main() {
    int len[] = {4, 3, 2, 6}; 
    int size = sizeof(len)/sizeof(len[0]); 
    cout << "\nTotal cost for connecting ropes is " << minCost(len, size); 
    return 0; 
}
