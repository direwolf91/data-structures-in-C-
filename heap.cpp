/*Heap needs to implement the following operations
    1. Insert
    2. Delete
    3. GetMin
    4. ExtractMin
    5. DecreaseKey

 */

#include<iostream>
using namespace std;

void swap (int*, int*);

void swap (int *x, int *y){
 int temp = *x;
 *x = *y;
 *y = temp;
}

class Heap
{
    int *harr; //pointer to array of elements in heap
    int capacity; //max possible size of the heap
    int heap_size; //current number of elements of the heap

public:
    Heap(int capacity); // Constructor for heap class that sets the capacity of the heap
    void insertKey(int);
    void deleteKey(int);
    int getMin();
    int extractMin();
    void decreaseKey(int, int);
    int parentKey(int);
    int leftChildKey(int);
    int rightChildKey(int);
    void heapify(int);
};

Heap::Heap(int cap){
    capacity = cap;
    heap_size = 0;
    harr = new int[cap];
}

int Heap::parentKey(int key){
    return (key - 1)/2;
}

int Heap::leftChildKey(int key){
    return (2*key + 1);
}

int Heap::rightChildKey(int key){
    return (2*key + 2);
}

void Heap::insertKey(int val){
    if (heap_size == capacity){
        cout << "\n Overflow: Could not insert key\n";
        return;
    }
    harr[heap_size] = val;
    int i = heap_size;
    heap_size++;
    while (i!=0 && harr[parentKey(i)] > harr[i]){
        swap(&harr[parentKey(i)], &harr[i]);
        i = parentKey(i);
    }
}

void Heap::deleteKey(int keyIndex){
    decreaseKey(keyIndex, INT_MIN);
    extractMin();
}

void Heap::decreaseKey(int keyIndex, int value){
    harr[keyIndex] = value;
    while (keyIndex!=0 && harr[parentKey(keyIndex)] > harr[keyIndex]){
        swap(&harr[parentKey(keyIndex)], &harr[keyIndex]);
        keyIndex = parentKey(keyIndex);
    }
}

int Heap::extractMin(){
    if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	heapify(0); 

	return root; 
}


void Heap::heapify(int index){
    int l = leftChildKey(index);
    int r = rightChildKey(index);
    int smallest = index;
    if (l < heap_size && harr[l] < harr[index]){
        smallest = l;
    }
     if (r < heap_size && harr[r] < harr[smallest]){
        smallest = r;
    }

    if (smallest != index){
        swap(&harr[smallest], &harr[index]);
        heapify(smallest);
    }
}

int Heap::getMin() { return harr[0]; } 


int main() 
{ 
	Heap h(11); 
	h.insertKey(3); 
	h.insertKey(2); 
	h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(2, 1); 
	cout << h.getMin(); 
	return 0; 
} 

